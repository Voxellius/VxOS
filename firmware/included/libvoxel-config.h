#ifndef LIBVOXEL_CONFIG_H_
#define LIBVOXEL_CONFIG_H_

#ifndef VOXEL_USE_CUSTOM_TYPES

#include <stdint.h>

#define VOXEL_BOOL int
#define VOXEL_COUNT unsigned int
#define VOXEL_INT_8 int8_t
#define VOXEL_INT_16 int16_t
#define VOXEL_INT_32 int32_t
#define VOXEL_UINT_8 uint8_t
#define VOXEL_UINT_16 uint16_t
#define VOXEL_UINT_32 uint32_t
#define VOXEL_FLOAT float
#define VOXEL_INTPTR intptr_t

#define VOXEL_MAX_PRECISION 6
#define VOXEL_NAN 0.0 / 0.0
#define VOXEL_INFINITY 1.0 / 0.0

#endif

#define VOXEL_BUILTINS_CORE
#define VOXEL_BUILTINS_IO
#define VOXEL_BUILTINS_THREADS

// #define VOXEL_DEBUG
// #define VOXEL_DEBUG_MEMORY
// #define VOXEL_DEBUG_THINGS
// #define VOXEL_DEBUG_EXECUTORS

#define VOXEL_LOG_UNHANDLED_EXCEPTIONS

#define VOXEL_STRING_BLOCK_SIZE 8
#define VOXEL_CALL_STACK_BLOCK_LENGTH 8
#define VOXEL_MAX_PROTOTYPE_TRAVERSE_DEPTH 16
#define VOXEL_MAX_BUFFER_WRITE_BLOCK 65536
// #define VOXEL_MAX_BUFFER_INIT_SIZE 16777216

#define VOXEL_MAGIC 'V', 'x', 'C', 0x01
#define VOXEL_MAGIC_SIZE 4

#ifdef VOXEL_USE_STDLIB

#include <stdio.h>
#include <stdlib.h>

void _voxel_log_stdlib(char* text) {
    printf("%s", text);
}

void _voxel_logByte_stdlib(char byte) {
    printf("%c", byte);
}

void _voxel_errorMessage_stdlib(const char* message, const char* detail, const char* function, const char* file, const int line) {
    printf("%s%s (%s in %s:%d)\n", message, detail, function, file, line);
}

void* _voxel_malloc(VOXEL_COUNT size) {
    return malloc(size);
}

void* _voxel_realloc(void* ptr, VOXEL_COUNT size) {
    return realloc(ptr, size);
}

void _voxel_free(void* ptr) {
    free(ptr);
}

#define VOXEL_LOG _voxel_log_stdlib
#define VOXEL_LOG_BYTE _voxel_logByte_stdlib
#define VOXEL_ERROR_MESSAGE _voxel_errorMessage_stdlib
#define VOXEL_MALLOC _voxel_malloc
#define VOXEL_REALLOC _voxel_realloc
#define VOXEL_FREE _voxel_free

#endif

void _voxel_log_stdlib(char* text) {
    Serial.print(text);
}

void _voxel_logByte_stdlib(char byte) {
    Serial.print(byte);
}

void _voxel_errorMessage_stdlib(const char* message, const char* detail, const char* function, const char* file, const int line) {
    Serial.print(message);
    Serial.print(detail);
    Serial.print(" (");
    Serial.print(function);
    Serial.print(" in ");
    Serial.print(file);
    Serial.print(":");
    Serial.print(line);
    Serial.println(")");
}

void* _voxel_malloc(VOXEL_COUNT size) {
    return malloc(size);
}

void* _voxel_realloc(void* ptr, VOXEL_COUNT size) {
    return realloc(ptr, size);
}

void _voxel_free(void* ptr) {
    free(ptr);
}

#define VOXEL_LOG _voxel_log_stdlib
#define VOXEL_LOG_BYTE _voxel_logByte_stdlib
#define VOXEL_ERROR_MESSAGE _voxel_errorMessage_stdlib
#define VOXEL_MALLOC _voxel_malloc
#define VOXEL_REALLOC _voxel_realloc
#define VOXEL_FREE _voxel_free

#endif