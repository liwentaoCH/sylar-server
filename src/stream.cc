#include "stream.h"
#include "log.h"

namespace sylar{
static sylar::Logger::ptr g_logger = SYLAR_LOG_NAME("system");

int Stream::readFixSize(void* buffer, size_t length){
    ssize_t offset = 0;
    ssize_t left = length;
    while(left > 0) {
        ssize_t len = read((char*)buffer + offset, left);
        if(len <= 0) {
            return len;
        }
        offset += len;
        left -= len;
    }
    return length;
}

int Stream::readFixSize(ByteArray::ptr ba, size_t length){
    ssize_t left = length;
    while(left > 0) {
        ssize_t len = read(ba, left);
        if(len <= 0) {
            return len;
        }
        left -= len;
    }
    return length;
}

int Stream::writeFixSize(const void* buffer, size_t length){
    ssize_t offset = 0;
    ssize_t left = length;
    while(left > 0) {
        ssize_t len = write((char*)buffer + offset, left);
        if(len <= 0) {
            return len;
        }
        offset += len;
        left -= len;
    }
    return length;
}

int Stream::writeFixSize(ByteArray::ptr ba, size_t length){
    ssize_t left = length;
    while(left > 0) {
        ssize_t len = write(ba, left);
        if(len <= 0) {
            return len;
        }
        left -= len;
    }
    return length;
}
}