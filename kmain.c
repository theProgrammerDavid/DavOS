#define FB_GREEN 2
#define FB_DARK_GREY 8

char *fb = (char*)0x000B8000;

struct example{
unsigned char config;
unsigned short address;
unsigned char index;
}__attribute__((packed));

int sum_of_three(int arg1, int arg2, int arg3){
return arg1 + arg2 + arg3;
}

void ifb_write_cell( unsigned int i,  char c, unsigned char fg, unsigned char bg)
{
fb[i] = c;
fb[i+1] = ((fg & 0x0F)<<4) | (bg & 0x0F);
}



void kmain(){

}
