/*******************************************************************************
* File Name: BACK_LIMIT_1.c  
* Version 1.90
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "BACK_LIMIT_1.h"


/*******************************************************************************
* Function Name: BACK_LIMIT_1_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None 
*  
*******************************************************************************/
void BACK_LIMIT_1_Write(uint8 value) 
{
    uint8 staticBits = (BACK_LIMIT_1_DR & (uint8)(~BACK_LIMIT_1_MASK));
    BACK_LIMIT_1_DR = staticBits | ((uint8)(value << BACK_LIMIT_1_SHIFT) & BACK_LIMIT_1_MASK);
}


/*******************************************************************************
* Function Name: BACK_LIMIT_1_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to this drive mode.
*
* Return: 
*  None
*
*******************************************************************************/
void BACK_LIMIT_1_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(BACK_LIMIT_1_0, mode);
}


/*******************************************************************************
* Function Name: BACK_LIMIT_1_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro BACK_LIMIT_1_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 BACK_LIMIT_1_Read(void) 
{
    return (BACK_LIMIT_1_PS & BACK_LIMIT_1_MASK) >> BACK_LIMIT_1_SHIFT;
}


/*******************************************************************************
* Function Name: BACK_LIMIT_1_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 BACK_LIMIT_1_ReadDataReg(void) 
{
    return (BACK_LIMIT_1_DR & BACK_LIMIT_1_MASK) >> BACK_LIMIT_1_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(BACK_LIMIT_1_INTSTAT) 

    /*******************************************************************************
    * Function Name: BACK_LIMIT_1_ClearInterrupt
    ********************************************************************************
    *
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 BACK_LIMIT_1_ClearInterrupt(void) 
    {
        return (BACK_LIMIT_1_INTSTAT & BACK_LIMIT_1_MASK) >> BACK_LIMIT_1_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
