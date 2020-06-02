#pragma once
typedef
struct SStudent_ {
 char name[256];
 int group;
 float rating;
}SStudent;

int Input1(const char *sf, SStudent ***s, int *count);
int Output1(const char *sf, SStudent **s, int count);
void Sort(SStudent **s, int count);
