// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Cesar Alejandro Roa Acosta and Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: Uart management functions
//              (PIC16F87x port)


module uart

@[inline]
pub fn read() rune{
  return C.RCREG
}


/*
fn uart.read() u16    // Almacena los datos recibidos 
{
    for(PIR1bits.RCIF == 0) {}  // Pregunta si hay datos recibidos  
    if(RCSTAbits.OERR == 1)     // Verifica que no haya errores 
    {
        RCSTAbits.CREN = 0      // Deshabilita la recepcion
        RCSTAbits.CREN = 1      // Habilita la recepcion 
    }
    PIR1bits.RCIF = 0    // Reinicia para que no hayan errores
    return RCREG         // Retorna los caracteres recibidos 
}
*/