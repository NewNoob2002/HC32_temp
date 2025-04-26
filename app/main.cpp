/*******************************************************************************
 * Include files
 ******************************************************************************/
#include "hc32_ddl.h"
/*******************************************************************************
 * Local type definitions ('typedef')
 ******************************************************************************/

/*******************************************************************************
 * Local pre-processor symbols/macros ('#define')
 ******************************************************************************/
/* LED0 Port/Pin definition */
#define  LED0_PORT        (PortB)
#define  LED0_PIN         (Pin14)

/* LED0~3 toggle definition */
#define  LED0_TOGGLE()    (PORT_Toggle(LED0_PORT, LED0_PIN))

#define  DLY_MS           (100ul)

/*******************************************************************************
 * Global variable definitions (declared in header file with 'extern')
 ******************************************************************************/

/*******************************************************************************
 * Local function prototypes ('static')
 ******************************************************************************/

/*******************************************************************************
 * Local variable definitions ('static')
 ******************************************************************************/

/*******************************************************************************
 * Function implementation - global ('extern') and local ('static')
 ******************************************************************************/
/**
 *******************************************************************************
 ** \brief  Main function of GPIO output
 **
 ** \param  None
 **
 ** \retval int32_t Return value, if needed
 **
 ******************************************************************************/
int32_t main(void)
{
    stc_port_init_t stcPortInit;

    /* configuration structure initialization */
    MEM_ZERO_STRUCT(stcPortInit);

    stcPortInit.enPinMode = Pin_Mode_Out;
    stcPortInit.enExInt = Enable;
    stcPortInit.enPullUp = Enable;

    /* LED0 Port/Pin initialization */
    PORT_Init(LED0_PORT, LED0_PIN, &stcPortInit);


    while(1)
    {
        LED0_TOGGLE();
        Ddl_Delay1ms(DLY_MS);
        /* de-init if necessary */
        //PORT_DeInit();
    };
}

/*******************************************************************************
 * EOF (not truncated)
 ******************************************************************************/
