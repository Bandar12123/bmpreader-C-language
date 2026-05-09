Advanced BMP Header Parser & Memory Analyzer
Overview

This program is an advanced tool for analyzing the structure of BMP (Bitmap) image files. It accesses the deep metadata stored in the file's binary header to extract technical information about how the image is stored, while simultaneously demonstrating memory management and pointer address tracking in C.

This project showcases several powerful programming concepts:

    Structural Data Analysis: Mapping a real-world binary file directly onto a C struct.

    Memory Address Tracking: Distinguishing between where data is stored and where pointers reside in the RAM.

    Direct Memory Access: Using void* and type casting to manipulate raw data buffers.

Technical Breakdown
1. Data Structure (struct BMPHeader)

The struct is meticulously designed to act as a "map" for the first 26 bytes of the file:

    Type & Size: Identification of the file format and its total footprint.

    Reserved 1 & 2: Standard placeholders reserved by the operating system (usually 0).

    Data Offset: The specific byte count from the start of the file to the beginning of the actual pixel data.

    Header Size: The size of the internal DIB (Device Independent Bitmap) header.

    Width & Height: The physical dimensions of the image in pixels.

2. Memory & Pointer Management

The code highlights a critical distinction in systems programming:

    The Data Block: The address pointed to by vptr and sptr (where the image data lives in the Heap).

    The Pointer Address: The location of the sptr variable itself in the Stack, printed using &sptr.

3. Program Analysis Flow

    Validation: It verifies the file starts with the "BM" signature (0x4D42).

    Extraction: It accurately parses the size and dimensions.

    Memory Debugging: It prints the memory address of the pointer variable using the %p format specifier.

Technical Considerations

    Memory Safety: The program uses free(vptr) to prevent memory leaks after the analysis is complete.

    Binary Integrity: The file is opened in rb (Read Binary) mode to prevent the system from misinterpreting binary bytes as text characters, ensuring numerical accuracy.

    Endianness: It assumes a Little-Endian architecture (standard for Intel/AMD), which matches the BMP file format.

Usage

    Prepare the file: Ensure an image named sample_1280×853.bmp is in the same directory as the source code.

    Compile:
    Bash

    gcc main.c -o bmp_analyzer

    Run:
    Bash

    ./bmp_analyzer

Example Output
Status: Valid BMP
---------------------------
File Type    : 4D42 (BM)
File Size    : 49 bytes
Reserved 1   : 0
Reserved 2   : 138
Data Offset  : 8126464 bytes
Header Size  : 83886080 bytes
Image Width  : 55902208 px
Image Height : 65536 px
Pointer Variable Address: 0x7ffc9abd8ab0
