#include <stdio.h>
#include <windows.h>

typedef int (*genKeyProto)( char* url, void*, char* buff );

int main( ) {
    char url[100];
    char buff[100] = {0};
    HMODULE lib  = LoadLibraryA("npnv3dv.dll");
    FARPROC npInitAddr;
    genKeyProto genKey;

    if (lib) {
        npInitAddr = GetProcAddress( lib, "NP_Initialize" );
        genKey = (genKeyProto) (npInitAddr + 0x84f0); 
   } else {
        printf("Not Loaded (error code %d)\n", GetLastError());
        return -1;
    }
    printf("*******************************************************\n");
    printf("**       NVIDIA 3D Vision Browser plugin keygen      **\n");
    printf("*******************************************************\n");
    printf("\n");
    printf( "Enter the site URL in the form (ie: http://yoursite.com/) : ");
    gets( url );
    genKey(url, 0, buff);
    printf( "\nYour Nvidia 3d Vision Site key for %s is :\n", &url);
    for (int i=0 ; buff[i] != '\0'; i++ )
    {
        printf("%02x", (unsigned char)buff[i]);
    }
    return 0;
}