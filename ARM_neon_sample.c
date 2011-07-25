/*
	
	ARM NEON sample code.
	By: ALI NUHI
	
	SIMD subsystem: single instruction, multiple data
	-run the same instruction on multiple piece of data
	
	neon registers:
	D0-D31 Registers: [...64bits...] OR Q0-Q15 Registers [...128bits...] 
	So if you have 32bit numbers you can load data into the Q register like so 
	[...32...|...32...|...32...|...32...] then do the same instruction such 
	as a multiply on all the numbers at the same time.
	
	Important to realize the system sees each register as a vector of data.
	
	to compile: use the options in GCC
	gcc FILENAME.C -march=armv7-a -mtune=cortex-a8 -mfpu=neon -ftree-vectorize -mfloat-abi=softfp -o OUTPUT
	if your using codesourcery gcc for cross compiling it would be 
	arm-none-linux-gnueabi-gcc (or g++ for cpp)
	
	Dont forget to include the arm_neon.h file.~
	
	Example instruction:
	VADD.I8 D0, D1, D2
	this is doing a neon add and the type of numbers your adding is 8bit Ints
	D1:[ 1 | 2 | 3 | 4 | 5 |  6  | 7  | 8 ]
			+
	D2:[ 1 | 2 | 3 | 4 | 5 |  6  | 7  | 8 ]
			=
	D0:[ 2 | 4 | 6 | 8 | 10 | 12 | 14 | 16 ]		
*/
#include <stdio.h>
#include <arm_neon.h>	//need to include this ifyou want to use intrinsics



int main(){

//vector addition 8x8 example.
	uint8x8_t vec_a, vec_b, vec_dest;  //a vector of 8 8bit ints
	vec_a = vdup_n_u8(9);
	vec_b = vdup_n_u8(10);

	vec_dest = vec_a * vec_b;
	int i = 0;
	int result;
	
	result = vget_lane_u8( vec_dest, 0 );
	printf( "Lane %d: %d\n", i, result );
	i++;
	result = vget_lane_u8( vec_dest, 1 );
	printf( "Lane %d: %d\n", i, result );
	i++;
	result = vget_lane_u8( vec_dest, 2 );
	printf( "Lane %d: %d\n", i, result );
	i++;
	result = vget_lane_u8( vec_dest, 3 );
	printf( "Lane %d: %d\n", i, result );
	i++;
	result = vget_lane_u8( vec_dest, 4 );
	printf( "Lane %d: %d\n", i, result );
	i++;
	result = vget_lane_u8( vec_dest, 5 );
	printf( "Lane %d: %d\n", i, result );
	i++;
	result = vget_lane_u8( vec_dest, 6 );
	printf( "Lane %d: %d\n", i, result );
	i++;
	result = vget_lane_u8( vec_dest, 7 );
	printf( "Lane %d: %d\n", i, result );

	float32_t p = 1.123456;
	float32_t o = 3.14159;
	
	float32_t *ptr_1, *ptr_2, *ptr_ans;
	float32_t vec1[12];
	float32_t vec_ans[12];
	

	
}
