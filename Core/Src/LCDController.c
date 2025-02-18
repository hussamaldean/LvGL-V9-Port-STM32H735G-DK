/*
 * LCDController.c
 *
 *  Created on: Feb 17, 2025
 *      Author: hussam
 */

#include "LCDController.h"
#include "main.h"
#include "ltdc.h"
#include "dma2d.h"


/*Screen Resolution*/
#define MY_DISP_HOR_RES 480
#define MY_DISP_VER_RES 272

/*Declare two drawing buffers*/
static lv_display_t * disp;

static uint8_t buf_1[MY_DISP_HOR_RES*MY_DISP_VER_RES*4]__attribute__ (( section(".HYPERRAM_data"), used));
static uint8_t buf_2[MY_DISP_HOR_RES*MY_DISP_VER_RES*4]__attribute__ (( section(".HYPERRAM_data"), used));

/*DMA2D transfer complete interrupt handler*/
static void disp_flush_complete (DMA2D_HandleTypeDef*);

/*Display flush function prototype*/
static void disp_flush (lv_display_t *, const lv_area_t *, uint8_t *);



void lv_port_disp_init(void)
{

	/*Create the display*/
	disp = lv_display_create(MY_DISP_HOR_RES, MY_DISP_VER_RES);

	/*Set the buffers*/
	lv_display_set_buffers(disp, (void*) buf_1, (void*) buf_2, sizeof(buf_1), LV_DISPLAY_RENDER_MODE_PARTIAL);


	/* interrupt callback for DMA2D transfer */
	hdma2d.XferCpltCallback = disp_flush_complete;

	lv_display_set_flush_cb(disp, disp_flush);

}

static void disp_flush (lv_display_t * display,
            const lv_area_t * area,
			uint8_t * px_map)
{


  lv_coord_t width = lv_area_get_width(area);
  lv_coord_t height = lv_area_get_height(area);

  SCB_CleanDCache_by_Addr((uint32_t *)px_map, width * height * 4);

  DMA2D->FGPFCCR = DMA2D_INPUT_ARGB8888;
  DMA2D->CR = 0x0U << DMA2D_CR_MODE_Pos;	// no conversion


  DMA2D->FGMAR = (uint32_t)px_map;
  DMA2D->FGOR = 0;

  DMA2D->OPFCCR = DMA2D_OUTPUT_ARGB8888;

  DMA2D->OMAR = hltdc.LayerCfg[0].FBStartAdress + 4 * \
                (area->y1 * MY_DISP_HOR_RES + area->x1);

  DMA2D->OOR = MY_DISP_HOR_RES - width;

  DMA2D->NLR = (width << DMA2D_NLR_PL_Pos) | (height << DMA2D_NLR_NL_Pos);

  DMA2D->IFCR = 0x3FU;

  DMA2D->CR |= DMA2D_CR_TCIE;

  DMA2D->CR |= DMA2D_CR_START;

}

static void disp_flush_complete (DMA2D_HandleTypeDef *hdma2d)
{
  lv_display_flush_ready(disp);
}


