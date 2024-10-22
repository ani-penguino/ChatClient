/*
 *
 * CSEE 4840 Lab 2 for 2019
 *
 * Name/UNI: Jiayi Wang jw4462 Yiyang Peng yp2655
 */
#include "fbputchar.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "usbkeyboard.h"
#include <pthread.h>
#include "convert.h"
/* Update SERVER_HOST to be the IP address of
 * the chat server you are connecting to
 */
/* arthur.cs.columbia.edu */
#define SERVER_HOST "128.59.19.114"
#define SERVER_PORT 42000

#define BUFFER_SIZE 128

/*
 * References:
 *
 * http://beej.us/guide/bgnet/output/html/singlepage/bgnet.html
 * http://www.thegeekstuff.com/2011/12/c-socket-programming/
 * 
 */

int sockfd; /* Socket file descriptor */

struct libusb_device_handle *keyboard;
uint8_t endpoint_address;

pthread_t network_thread;
void *network_thread_f(void *);

void clearLine(int verticalPosition) {
    for (int i = 0; i < 64; i++) { // Hardcoded monitor width of 64 characters
        fbputchar(' ', verticalPosition, i); // Assuming fbputchar places a char on the display
    }
}

int main()
{
  int err, col;

  struct sockaddr_in serv_addr;

  struct usb_keyboard_packet packet;
  int transferred;
  char keystate[12];

  if ((err = fbopen()) != 0) {
    fprintf(stderr, "Error: Could not open framebuffer: %d\n", err);
    exit(1);
  }
  
  int verpos, horpos; 
  for (verpos = 0; verpos < 23; verpos++) {
        for (horpos = 0; horpos < 64; horpos++) {
            fbputchar(' ', verpos, horpos);
        }
    }

  /* Draw rows of asterisks across the top and bottom of the screen */
  for (col = 0 ; col < 64 ; col++) {
    fbputchar('*', 0, col);
    fbputchar('*', 20, col);
    fbputchar('*', 23, col);
  }

  /* Open the keyboard */
  if ( (keyboard = openkeyboard(&endpoint_address)) == NULL ) {
    fprintf(stderr, "Did not find a keyboard\n");
    exit(1);
  }
    
  /* Create a TCP communications socket */
  if ( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0 ) {
    fprintf(stderr, "Error: Could not create socket\n");
    exit(1);
  }

  /* Get the server address */
  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(SERVER_PORT);
  if ( inet_pton(AF_INET, SERVER_HOST, &serv_addr.sin_addr) <= 0) {
    fprintf(stderr, "Error: Could not convert host IP \"%s\"\n", SERVER_HOST);
    exit(1);
  }

  /* Connect the socket to the server */
  if ( connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    fprintf(stderr, "Error: connect() failed.  Is the server running?\n");
    exit(1);
  }

  /* Start the network thread */
  pthread_create(&network_thread, NULL, network_thread_f, NULL);

  /* Look ek;
        }
    }
}
or and handle keypresses */
	char longSentence[BUFFER_SIZE] = {0};
        int horizontalPosition = 0;
        int verticalPosition = 21;
	int length = 1;

for (;;) {
    libusb_interrupt_transfer(keyboard, endpoint_address,
                              (unsigned *)&packet, sizeof(packet),
                              &transferred, 0);
    if (transferred == sizeof(packet)) {
        sprintf(keystate, "%02x %02x %02x", packet.modifiers, packet.keycode[0],
                packet.keycode[1]);

	
	char *letter = convert(keystate);

        if (!letter) {
            write(sockfd, longSentence, horizontalPosition);
            break;
        }else if (*letter == (char)1 && horizontalPosition>0) {
	  longSentence[horizontalPosition] = longSentence[horizontalPosition-1];
	  horizontalPosition--;
	}else if (*letter == (char)2 && horizontalPosition < length-1) {
	  longSentence[horizontalPosition] = longSentence[horizontalPosition+1];
	  horizontalPosition++;
	}else if (*letter == (char)13) {
	    while(longSentence[horizontalPosition+1]!='\0'){
	      longSentence[horizontalPosition] = longSentence[horizontalPosition+1];
	      horizontalPosition++;
	    }
            write(sockfd, longSentence, horizontalPosition);
	    horizontalPosition=0;
	    length=1;
        } else if (*letter == (char)8 && horizontalPosition>0) {
	    horizontalPosition--;
	    length--;
            if (horizontalPosition >= 0) {
	      for(int k=horizontalPosition;k<length;k++){
		longSentence[k] = longSentence[k+1];
	      }
            }
        } else if(*letter != (char)2 && *letter != (char)1 && *letter != (char)8) {
            while (letter && *letter && horizontalPosition < BUFFER_SIZE - 2 && length < BUFFER_SIZE-1) {
		for(int k=length;k>=horizontalPosition;k--){
		  longSentence[k] = longSentence[k-1];
	        }
		longSentence[horizontalPosition] = *letter;
                horizontalPosition++;
                letter++;
		length++;
            }
        }
	longSentence[horizontalPosition] = '\n';
	longSentence[length] = '\0';

        // Clear the line at the vertical position before printing
        for (int i = 0; i < 64; i++) {
	  for (int j = 0; j<2; j++) {
            fbputchar(' ', verticalPosition+j, i);
	  }
        }

        fbputs(longSentence, verticalPosition, 0);

        if (packet.keycode[0] == 0x29) {
            break;
        }
    }
}





  /* Terminate the network thread */
  pthread_cancel(network_thread);

  /* Wait for the network thread to finish */
  pthread_join(network_thread, NULL);

  return 0;
}

void *network_thread_f(void *ignored) {
    char recvBuf[BUFFER_SIZE];
    int n;
    int line = 1; // Initialize line counter to manage vertical positioning

    /* Receive data */
    while ((n = read(sockfd, &recvBuf, BUFFER_SIZE - 1)) > 0) {
      if (line==1){
	// Clear the line at the vertical position before printing
	for (int i = 0; i < 64; i++) {
	  for (int j=0; j<16; j++){
	    fbputchar(' ', j, i);
	  }
	}
      }
      recvBuf[n] = '\0';
      printf("%s", recvBuf);
      
      fbputs(recvBuf, line, 0); // Increment line for each message
      line+=(n+63)/64;
      // Reset line if it exceeds screen limits (optional)
      if (line >= 15) {
	line = 1; // Reset to top or implement scrolling
      }
    }

    return NULL;
}


