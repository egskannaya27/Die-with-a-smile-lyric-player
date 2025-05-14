/*
MIT License

Copyright (c) 2025 Guru Sai Prasanna Eppanapally 

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
#include <windows.h>
#define qpf QueryPerformanceFrequency 
#define qpc QueryPerformanceCounter 
void wms(int ms){
    Sleep(ms);
}
long gct(){
    LARGE_INTEGER fr,ti;
    qpf(&fr);
    qpc(&ti);
    return (long)(ti.QuadPart*1000/fr.QuadPart);
}
#else
#include <unistd.h>
#include <sys/time.h>
void wms(int ms) {
    usleep(ms*1000);
}
long gct(){
    struct timeval tv;
    gettimeofday(&tv,NULL);
    return(tv.tv_sec*1000)+(tv.tv_usec/1000);
}
#endif
typedef struct{
    const char*line;
    int st,et;  
} LL;
LL lyrics[]={
    {"If the world was ending, I'd wanna be next to you", 0, 8970},
    {"If the party was over and our time on Earth was through", 9480, 19090},
    {"I'd wanna hold you just for a while and die with a smile", 19100, 29500},
    {"If the world was ending, I'd wanna be next to you", 29010, 37100}
};
int main(){
    int nl=sizeof(lyrics)/sizeof(lyrics[0]);
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
    long s=gct();
    printf("Song: Die with a smile\n");
    printf("\n");
    wms(1000);
    for(int i=0;i<nl;i++){
        LL cur=lyrics[i];
        long tar=s+cur.st;
        while(gct()<tar){
            wms(1);
        }
        int len=strlen(cur.line);
        int dur=cur.et-cur.st;
        int del;
        if(i==1){
            int p1=3000;
            int gd=500;
            int p2=2600;
            int tt=dur;
            for(int j=0;j<len;j++){
                if(j<21)
                    del=p1/21;
                else if(j==21)
                    del=gd;
                else
                    del=p2/26;
                printf("%c",cur.line[j]);
                fflush(stdout);
                wms(del);
            }
        } 
        else if(i==2){
            int p1=4050;
            int p2=5175;
            int p3=1125;
            int tt=dur;
            for(int j=0;j<len;j++){
                if(j<27)
                    del=p1/27;
                else if(j<32)
                    del=(p2-p1)/5;
                else
                    del=p3/19;
                printf("%c",cur.line[j]);
                fflush(stdout);
                wms(del);
            }
        } 
        else{
            del=(dur/len)*2/3;
            for(int j=0;j<len;j++){
                printf("%c",cur.line[j]);
                fflush(stdout);
                wms(del);
            }
        }
        printf("\n");
        if(i<nl-1){
            long now=gct();
            long nxt=s+lyrics[i+1].st;
            if(now<nxt)
                wms(nxt-now);
        }
    }
    printf("\nThank you...!\n@i_am_ironman1627\n");
    printf("\n");
    return 0;
}