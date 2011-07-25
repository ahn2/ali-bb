/*

Inline ARM assembly in C
By: ALI NUHI

compiled on 32bit w7 machine using cygwin and codesourcery using command:
arm-none-linux-gnueabi-gcc ARM_inline_assembly_sample.C -march=armv7-a -mtune=cortex-a8 -o arm_asm

*/
#include <stdio.h>

int main(){

//NOP
	asm( "mov r0, r0" );
	asm( "NOP" );

//MOVE NOT
//load a register with compliment of immediate or reg
//initialize the result variable
	int not_55 = 1;
	printf( "The valueu of not_55 before asm MVN instruction\n" );
	printf( "not_55 = 0x%x\n", not_55 );
	
	__asm__ __volatile__( "mvn %[not_55], #0x55" : [ not_55 ]"=r"( not_55 ) : );
	
	printf( "After instruction: not_55 = 0x%x", not_55 );
	printf( "----------------\n" );
	
//MUL example. Result = Value*Scale	
	int value = 0xFF;
	int scale = 0xFF;
	int result = 1;
	
	printf( "Before MUL instruction\n" );
	printf( "Value = 0x%x\n Scale = 0x%x\n Result = 0x%x\n", value, scale, result );
	
	__asm( "MUL %[result], %[value], %[scale]"
	      : [result]"=r"(result)			
	      : [value]"r"(value), [scale]"r"(scale) );
	
	printf( "After MUL instruction\n" );
	printf( "Value = 0x%x\n Scale = 0x%x\n Result = 0x%x\n", value, scale, result );
	printf( "----------------\n" );

	
//testing moving between registers and vars
	
	asm( "MOV R11, #0xFF" );
	printf( "Moving 0xFF into Register 11\n" );
	printf( "R10 = R11 * R11, using MUL instruction\n" );
	asm( "MUL R10, R11, R11" );
	printf( "the value of after_mul before contents of R10 are moved to it\n" );
	int after_mul = 0;
	printf( "after_mul = %d\n", after_mul );
	asm( "MOV %[after_mul], R10" : [after_mul]"=r"(after_mul) : );
	printf( "After Multiply(0xFF*0xFF)\n" );
	printf( "after_mul = %d\n", after_mul );

	
}

