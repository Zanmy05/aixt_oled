// This Arduino code was automatically generated by Aixt Project
//     https://github.com/fermarsan/aixt
// Device = Arduino-Nano
// Board = Arduino Nano
// Backend = arduino

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;
typedef int8_t isize;
typedef int32_t int_literal;
typedef uint8_t u8;
// typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef uint8_t usize;
typedef float f32;
typedef double f64;
typedef double float_literal;
typedef char rune;

#define _const_main__cpu_freq_mhz	_const_main__cpu_freq/1000000
#define _const_main__cpu_freq  16000000

#define _const_main__led_0 13

#define time__sleep(ts) delay(ts * 1000)

#define time__sleep_ms(tms) delay(tms)

#define time__sleep_us(tus) delayMicroseconds(tus)

#define _const_pin__d0 0
#define _const_pin__d1 1
#define _const_pin__d2 2
#define _const_pin__d3 3
#define _const_pin__d4 4
#define _const_pin__d5 5
#define _const_pin__d6 6
#define _const_pin__d7 7
#define _const_pin__d8 8
#define _const_pin__d9 9
#define _const_pin__d10 10
#define _const_pin__d11 11
#define _const_pin__d12 12
#define _const_pin__d13 13
#define _const_pin__d14 14
#define _const_pin__d15 15
#define _const_pin__d16 16
#define _const_pin__d17 17
#define _const_pin__d18 18
#define _const_pin__d19 19
#define _const_pin__d20 20
#define _const_pin__d21 21
#define _const_pin__input 0
#define _const_pin__output 1
#define _const_pin__in_pullup 2

#define pin__read(name)  digitalRead(name)

#define pin__low(name) digitalWrite(name, LOW)

#define pin__write(name, val) digitalWrite(name, val)

#define pin__setup(name, mode) pinMode(name, mode)

#define pin__high(name) digitalWrite(name, HIGH)

#define _const_port__b 0
#define _const_port__c 1
#define _const_port__d 2
#define _const_port__all_inputs 0b11111111
#define _const_port__all_outputs 0b00000000

#define port__read(name)  (u8)(*(&PINB + (name * 3)))

#define port__write(name, value) *(&PORTB + (name * 3)) = value

#define port__setup(name, mode) *(&DDRB + (name * 3)) = ~mode

#define _const_adc__ch0 14
#define _const_adc__ch1 15
#define _const_adc__ch2 16
#define _const_adc__ch3 17
#define _const_adc__ch4 18
#define _const_adc__ch5 19
#define _const_adc__ch6 20
#define _const_adc__ch7 21

#define adc__read(name)  analogRead(name)

void setup() {
	pin__setup(_const_adc__ch0, _const_pin__input); 
	port__setup(_const_port__d, _const_port__all_outputs); 
	pin__setup(_const_pin__d8, _const_pin__output); 
	i32 vck = (i32)(0); 
	i32 vfk = (i32)(0); 
	i32 vck_1 = (i32)(0); 
	i32 vfk_1 = (i32)(0); 
	while( true ) {
		vfk_1 = (i32)(vfk); 
		vck_1 = (i32)(vck); 
		vfk = (i32)(adc__read(_const_adc__ch0) >> 2); 
		vck = (i32)((i32)((f32)(vck_1) * (f32)(0.8187) + (f32)(vfk_1) * (f32)(0.1813))); 
		port__write(_const_port__d, (u8)(vck)); 
		pin__high(_const_pin__d8); 
		pin__low(_const_pin__d8); 
	} 
}

void loop(){
}
