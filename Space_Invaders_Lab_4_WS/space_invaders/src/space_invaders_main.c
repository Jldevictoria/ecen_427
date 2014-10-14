/*
 * Copyright (c) 2009 Xilinx, Inc.  All rights reserved.
 *
 * Xilinx, Inc.
 * XILINX IS PROVIDING THIS DESIGN, CODE, OR INFORMATION "AS IS" AS A
 * COURTESY TO YOU.  BY PROVIDING THIS DESIGN, CODE, OR INFORMATION AS
 * ONE POSSIBLE   IMPLEMENTATION OF THIS FEATURE, APPLICATION OR
 * STANDARD, XILINX IS MAKING NO REPRESENTATION THAT THIS IMPLEMENTATION
 * IS FREE FROM ANY CLAIMS OF INFRINGEMENT, AND YOU ARE RESPONSIBLE
 * FOR OBTAINING ANY RIGHTS YOU MAY REQUIRE FOR YOUR IMPLEMENTATION.
 * XILINX EXPRESSLY DISCLAIMS ANY WARRANTY WHATSOEVER WITH RESPECT TO
 * THE ADEQUACY OF THE IMPLEMENTATION, INCLUDING BUT NOT LIMITED TO
 * ANY WARRANTIES OR REPRESENTATIONS THAT THIS IMPLEMENTATION IS FREE
 * FROM CLAIMS OF INFRINGEMENT, IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 * Taylor Simons + Joseph DeVictoria
 * ECEN 425 Lab 3 aliens source.
 */

// Includes
#include <stdio.h>
#include "bitmap.h"
#include "stdlib.h"
#include "platform.h"
#include "xparameters.h"
#include "xaxivdma.h"
#include "xgpio.h"
#include "xio.h"
#include "time.h"
#include "unistd.h"
#include "mb_interface.h"
#include "xintc_l.h"
#include "globals.h"

_Bool bs[4] = {1,1,1,1};
int bNum = 0;
int alienMarchSpeed = 80;
unsigned int * framePointer = (unsigned int *) FRAME_BUFFER_0_ADDR;

XGpio gpPB;   // This is a handle for the push-button GPIO block.

void clearBullet(int sel){
	int tempY = 0;
	int tempX = 0;
	switch(sel){
	case 0:
		tempY = aBullet0Y;
		tempX = aBullet0X;
		break;
	case 1:
		tempY = aBullet1Y;
		tempX = aBullet1X;
		break;
	case 2:
		tempY = aBullet2Y;
		tempX = aBullet2X;
		break;
	case 3:
		tempY = aBullet3Y;
		tempX = aBullet3X;
		break;
	case 4:
		tempY = tBulletY + 14;
		tempX = tBulletX;
		break;
	}
	int row,col;
	for (row = 0; row < 14; row ++){
		for (col = 0; col < 8; col ++){
			framePointer[(tempY+row)*640+tempX+col] = 0x00000000;
		}
	}

}

void control(int input){
	// Get command from user.
	char cmd = input;
	if (cmd == 4){
		xil_printf("%c\r\n", cmd);
		if (tankX > X_BOUND_RIGHT)
			tankX -= 4;
		render(4);
		xil_printf("%d\r\n", tankX);
	}
	if (cmd == 6){
		xil_printf("%c\r\n", cmd);
		if (tankX < X_BOUND_LEFT - TANK_WIDTH)
			tankX += 4;
		render(6);
		xil_printf("%d\r\n", tankX);
	}
	if (cmd == 8){
		xil_printf("%c\r\n", cmd);
		aBlockT = !aBlockT;
		if ((aBlockD == 1) && (aBlockX >= X_BOUND_LEFT - A_BLOCK_WIDTH - BLOCK_SHIFT)){
			aBlockD = 0;
			aBlockY += BLOCK_SHIFT;
		}else if ((aBlockD == 0) && (aBlockX <= X_BOUND_RIGHT + BLOCK_SHIFT)){
			aBlockD = 1;
			aBlockY += BLOCK_SHIFT;
		}else if (aBlockD == 1){
			aBlockX += BLOCK_SHIFT;
		}else if (aBlockD == 0){
			aBlockX -= BLOCK_SHIFT;
		}
		drawInvaderBlock();
	}
	if (cmd == 2){
		xil_printf("%c\r\n", cmd);
		xil_printf("Please provide the number of the alien you want to kill\n\r");
		int toKill;
		scanf("%d", &toKill);
		xil_printf("%d\r\n", toKill);
		if ((toKill >= 0) & (toKill < 55)){
			alien_life[toKill] = 0;
			if (alien_life[toKill] == 0){
				xil_printf("Killed alien #%d\n\r", toKill);
			}else{
				xil_printf("Error\n\r");
			}
		}
		render(2);
	}
	if (cmd == 5){
		xil_printf("%c\r\n", cmd);
		if(ts){
			ts = 0;
			tBulletX = tankX+16;
			tBulletY = tankY-12;
			render(5);
		}
	}
	if (cmd == 3){
		xil_printf("%c\r\n", cmd);
		random = rand()%11;
		randomT = rand()%2;
		while (alien_life[random+44] != 1){
			random = rand()%11;
		}
		int i;
		if(bNum < 4){
			bDone = 0;
			for(i=0; i<4; i++){
				if(!bDone){
					if (bs[i] == 1){
						bDone = 1;
						bNum++;
						bs[i] = 0;
						switch(i){
						case 0:
							aBullet0X = aBlockX + (random*32) + A_B_X_OFF;
							aBullet0Y = aBlockY + INV_VERT*5;
							aBullet0T = randomT;
							break;
						case 1:
							aBullet1X = aBlockX + (random*32) + A_B_X_OFF;
							aBullet1Y = aBlockY + INV_VERT*5;
							aBullet1T = randomT;
							break;
						case 2:
							aBullet2X = aBlockX + (random*32) + A_B_X_OFF;
							aBullet2Y = aBlockY + INV_VERT*5;
							aBullet2T = randomT;
							break;
						case 3:
							aBullet3X = aBlockX + (random*32) + A_B_X_OFF;
							aBullet3Y = aBlockY + INV_VERT*5;
							aBullet3T = randomT;
							break;
						default:
							break;
						}
					}
				}
			}
		}
		render(3);
	}
	if (cmd == 9){
		xil_printf("%c\r\n", cmd);
		int i;
		if(bNum > 0){
			for(i=0; i<4; i++){
				if (bs[i] == 0){
					switch(i){
					case 0:
						if (aBullet0Y >= GREEN_LINE_ROW - (A_B_MOVE * 2)){
							bs[i] = 1;
							bNum--;
							clearBullet(0);
						}
						aBullet0Y += A_B_MOVE;
						abs0 = !abs0;
						break;
					case 1:
						if (aBullet1Y >= GREEN_LINE_ROW - (A_B_MOVE * 2)){
							bs[i] = 1;
							bNum--;
							clearBullet(1);
						}
						aBullet1Y += A_B_MOVE;
						abs1 = !abs1;
						break;
					case 2:
						if (aBullet2Y >= GREEN_LINE_ROW - (A_B_MOVE * 2)){
							bs[i] = 1;
							bNum--;
							clearBullet(2);
						}
						aBullet2Y += A_B_MOVE;
						abs2 = !abs2;
						break;
					case 3:
						if (aBullet3Y >= GREEN_LINE_ROW - (A_B_MOVE * 2)){
							bs[i] = 1;
							bNum--;
							clearBullet(3);
						}
						aBullet3Y += A_B_MOVE;
						abs3 = !abs3;
						break;
					default:
						break;
					}
				}
			}
		}
		if (!ts){
			tBulletY -= 14;
			if (tBulletY <= TOP_BULLET_END){
				clearBullet(4);
				ts = 1;
			}
		}
		render(9);
	}
	if (cmd == 7){
		xil_printf("%c\r\n", cmd);
		xil_printf("%c\r\n", cmd);
		xil_printf("Please provide the number of the bunker you want to erode\n\r");
		int toErode;
		scanf("%d", &toErode);
		xil_printf("%d\r\n", toErode);
		toErode = 3 - toErode;
		if ((toErode >= 0) & (toErode < 4)){
			int random = rand()%10;
			while (bErosion[toErode][random] > 3){
				random = rand()%10;
			}
			bErosion[toErode][random]++;
		}
		render(7);
	}
	return;
}

void pollButtons(){
	currentButtonState = XGpio_DiscreteRead(&gpPB, 1);  // Get the current state of the buttons.
	//xil_printf("poll the buttons! %d \n\r", currentButtonState);
	char left = currentButtonState&(0x8);
	char mid = currentButtonState&(0x1);
	char right = currentButtonState&(0x2);
	//char up = currentButtonState&(0x10);
	//char down = currentButtonState&(0x4);
	if (left){
		control(4);
	}
	if (right){
		control(6);
	}
	if (mid){
		control(5);
	}
}

void updatePositions(){
	if ((fit_counter % alienMarchSpeed) == 0){
		control(8);
	}
	if ((fit_counter % BULLET_MOVE_SPEED) == 0){
		control(9);
	}
}

void drawGreenLine(){
	int row,col;
	for(row = 0; row < 2; row ++){
		for (col = 0; col < X_BOUND_LEFT - X_BOUND_RIGHT; col ++){
			framePointer[(GREEN_LINE_ROW+row)*640+X_BOUND_RIGHT+col] = 0x0000FF00;
		}
	}
}

// This is invoked in response to a timer interrupt.
void timer_interrupt_handler() {
	fit_counter++;
	//xil_printf("A FIT interrupt came in! %d \n\r", fit_counter);
	pollButtons();
	updatePositions();
}

// Main interrupt handler, queries the interrupt controller to see what peripheral
// fired the interrupt and then dispatches the corresponding interrupt handler.
// This routine acks the interrupt at the controller level but the peripheral
// interrupt must be ack'd by the dispatched interrupt handler.
void interrupt_handler_dispatcher(void* ptr) {
	int intc_status = XIntc_GetIntrStatus(XPAR_INTC_0_BASEADDR);
	// Check the FIT interrupt first.
	if (intc_status & XPAR_FIT_TIMER_0_INTERRUPT_MASK){
		XIntc_AckIntr(XPAR_INTC_0_BASEADDR, XPAR_FIT_TIMER_0_INTERRUPT_MASK);
		timer_interrupt_handler();
	}
}

int main(){
	init_platform();                   // Necessary for all programs.
	int Status;                        // Keep track of success/failure of system function calls.
	XAxiVdma videoDMAController;
	// There are 3 steps to initializing the vdma driver and IP.
	// Step 1: lookup the memory structure that is used to access the vdma driver.
    XAxiVdma_Config * VideoDMAConfig = XAxiVdma_LookupConfig(XPAR_AXI_VDMA_0_DEVICE_ID);
    // Step 2: Initialize the memory structure and the hardware.
    if(XST_FAILURE == XAxiVdma_CfgInitialize(&videoDMAController, VideoDMAConfig,	XPAR_AXI_VDMA_0_BASEADDR)) {
    	xil_printf("VideoDMA Did not initialize.\r\n");
    }
    // Step 3: (optional) set the frame store number.
    if(XST_FAILURE ==  XAxiVdma_SetFrmStore(&videoDMAController, 2, XAXIVDMA_READ)) {
    	xil_printf("Set Frame Store Failed.");
    }
    // Initialization is complete at this point.

    // Setup the frame counter. We want two read frames. We don't need any write frames but the
    // function generates an error if you set the write frame count to 0. We set it to 2
    // but ignore it because we don't need a write channel at all.
    XAxiVdma_FrameCounter myFrameConfig;
    myFrameConfig.ReadFrameCount = 2;
    myFrameConfig.ReadDelayTimerCount = 10;
    myFrameConfig.WriteFrameCount =2;
    myFrameConfig.WriteDelayTimerCount = 10;
    Status = XAxiVdma_SetFrameCounter(&videoDMAController, &myFrameConfig);
    if (Status != XST_SUCCESS) {
	   xil_printf("Set frame counter failed %d\r\n", Status);
	   if(Status == XST_VDMA_MISMATCH_ERROR)
		   xil_printf("DMA Mismatch Error\r\n");
    }
    // Now we tell the driver about the geometry of our frame buffer and a few other things.
    // Our image is 480 x 640.
    XAxiVdma_DmaSetup myFrameBuffer;
    myFrameBuffer.VertSizeInput = 480;    // 480 vertical pixels.
    myFrameBuffer.HoriSizeInput = 640*4;  // 640 horizontal (32-bit pixels).
    myFrameBuffer.Stride = 640*4;         // Dont' worry about the rest of the values.
    myFrameBuffer.FrameDelay = 0;
    myFrameBuffer.EnableCircularBuf=1;
    myFrameBuffer.EnableSync = 0;
    myFrameBuffer.PointNum = 0;
    myFrameBuffer.EnableFrameCounter = 0;
    myFrameBuffer.FixedFrameStoreAddr = 0;
    if(XST_FAILURE == XAxiVdma_DmaConfig(&videoDMAController, XAXIVDMA_READ, &myFrameBuffer)) {
    	xil_printf("DMA Config Failed\r\n");
     }
    // We need to give the frame buffer pointers to the memory that it will use. This memory
    // is where you will write your video data. The vdma IP/driver then streams it to the HDMI
    // IP.
     myFrameBuffer.FrameStoreStartAddr[0] = FRAME_BUFFER_0_ADDR;
     myFrameBuffer.FrameStoreStartAddr[1] = FRAME_BUFFER_0_ADDR + 4*640*480;

     if(XST_FAILURE == XAxiVdma_DmaSetBufferAddr(&videoDMAController, XAXIVDMA_READ,
    		               myFrameBuffer.FrameStoreStartAddr)) {
    	 xil_printf("DMA Set Address Failed Failed\r\n");
     }
     // Print a sanity message if you get this far.
     //xil_printf("Woohoo! I made it through initialization.\n\r");
     // Now, let's get ready to start displaying some stuff on the screen.
     // The variables framePointer and framePointer1 are just pointers to the base address
     // of frame 0 and frame 1.

     //unsigned int * framePointer1 = ((unsigned int *) FRAME_BUFFER_0_ADDR) + 640*480;
     // Just paint some large red, green, blue, and white squares in different
     // positions of the image for each frame in the buffer (framePointer0 and framePointer1).
     //    			 framePointer[row*640 + col] = 0x0000FF00;  // frame 1 is green here.



     // This tells the HDMI controller the resolution of your display (there must be a better way to do this).
     XIo_Out32(XPAR_AXI_HDMI_0_BASEADDR, 640*480);

     // Start the DMA for the read channel only.
     if(XST_FAILURE == XAxiVdma_DmaStart(&videoDMAController, XAXIVDMA_READ)){
    	 xil_printf("DMA START FAILED\r\n");
     }
     int frameIndex = 0;
     // We have two frames, let's park on frame 0. Use frameIndex to index them.
     // Note that you have to start the DMA process before parking on a frame.
     if (XST_FAILURE == XAxiVdma_StartParking(&videoDMAController, frameIndex,  XAXIVDMA_READ)) {
    	 xil_printf("vdma parking failed\n\r");
     }


     // Initialize the GPIO peripherals.
     int success;
     // print("hello world\n\r");
     success = XGpio_Initialize(&gpPB, XPAR_PUSH_BUTTONS_5BITS_DEVICE_ID);
     // success = XGpio_Initialize(&gpPB, XPAR_PUSH_BUTTONS_5BITS_DEVICE_ID);

     // Set the push button peripheral to be inputs.
     XGpio_SetDataDirection(&gpPB, 1, 0x0000001F);
     // Enable the global GPIO interrupt for push buttons.
     //XGpio_InterruptGlobalEnable(&gpPB);
     // Enable all interrupts in the push button peripheral.
     //XGpio_InterruptEnable(&gpPB, 0xFFFFFFFF);


     microblaze_register_handler(interrupt_handler_dispatcher, NULL);
     XIntc_EnableIntr(XPAR_INTC_0_BASEADDR, XPAR_FIT_TIMER_0_INTERRUPT_MASK);
     XIntc_MasterEnable(XPAR_INTC_0_BASEADDR);
     microblaze_enable_interrupts();

     //initilize bunker status
     int bunk;
     int blk;
     for(bunk = 0; bunk < 4; bunk++){
    	 for(blk = 0; blk < 10; blk ++){
    		 bErosion[bunk][blk] = 0;
    	 }
     }

     // Write black to all pixels in frame buffer.
     // This is sort of a default
     int row, col;
     for(row=0; row <480; row++){
     	 for(col=0; col<640; col++){
     		 framePointer[row*640+col] = 0x00000000;
       	 }
     }
     srand(time(0));
     // Initialize positions
     tankX = 304;					// Tank Initial Position.
     tankY = TANK_ROW;
     aBlockX = 144;					// Alien Block Initial Position.
     aBlockY = A_B_Y_INIT;
     aBlockT = 0;
     aBlockD = 1;
     ts = 1;

     // Initialize alien array.
     int a;
     for (a=0; a<55; a++){
    	 alien_life[a] = 1;
     }

     render(8);
     render(4);
     render(7);

     drawGreenLine();
     while(1){
     }

     cleanup_platform();

    return 0;
}