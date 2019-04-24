#pragma once

int readCount;
struct Entry* ReadBinEntry(const char* path);
void WriteBinEntry(struct Entry* entries, int count, const char* path);