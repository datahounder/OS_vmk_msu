#include <stdio.h>
#include <stdlib.h>
#include <string.h>


unsigned char GetByte(const char data[])
{
   unsigned char byte = 0;
   const char* end = data + 8;
 
   for (; *data && (data < end); ++data)
   {
      byte <<= 1;
 
      byte |= (*data == '1') ? 1 : 0;
   }
 
   return byte;
}

char* GetBits(unsigned char byte, char bits[])
{
   size_t i;
   for (i = 0; i < 8; ++i)
   {
      bits[7 - i] = (byte & 1) ? '1' : '0';
      byte >>= 1;
   }
 
   return bits;
}

long int filesize(FILE *fp)
  {
    long int save_pos, size_of_file;
    save_pos = ftell( fp );
    fseek( fp, 0L, SEEK_END );
    size_of_file = ftell( fp );
    fseek( fp, save_pos, SEEK_SET );
    return( size_of_file );
  }

int main(int argc, char **argv) {
    if(argc != 4){
        printf("syntax : %s pack  or unpack [path of inputfile] [path of outputfile]\n", argv[0]);
        return 0;
    }
    if((!strcmp(argv[1], "pack"))&&(!strcmp(argv[1], "unpack" ))){
        printf("You requested pack or unpack.\n");   
        printf("Unknown parameter: '%s'. Type syntax error :  use pack  or  unpack [path of inputfile] [path of outputfile].\n", argv[1]);    
        return 1;       
    } 

    const char a[] = "111";
    const char t[] = "110";
    const char g[] = "101";
    const char c[] = "100";
    const char u[] = "011";
    const char n[] = "010";
               
    
    if(strcmp(argv[1], "pack")==0){
        printf("pack\n");
        int i;
        int slash=0;
        int karetka=0;
        char ch; 
        //const char str[1024]; 

        char *InputPath;
        char *OutputPath;
        InputPath = argv[2];
        OutputPath = argv[3];

        FILE * stream;            
        stream = fopen(InputPath,"r"); 
        printf("%s\n", InputPath); 
           
        FILE* f = fopen(OutputPath, "wb");
        printf("%s\n", OutputPath);

        if (f == NULL){
            perror("output file does not exist\n");
            return EXIT_FAILURE;
        }
        else{
        printf("output file loaded: '%s'\n", OutputPath);
        }

        if (stream == NULL){
            perror("input file does not exist\n");
            return EXIT_FAILURE;
        }
        else{
            printf("input file loaded: '%s'\n", InputPath);
        }

        if (feof(stream)){
            perror("input file is empty\n");
            return EXIT_FAILURE;    
        }
        else{
           printf("input file is not empty: '%s'\n", InputPath); 
        }      
        char data[11];
        memset(&data, 0, sizeof(data));
        int count=0;    
        char qzx; 
        char qzx1;  
        char qzx2; 
        char data1[9];     
        memset(&data1, 0, sizeof(data1));     
        while (!feof(stream)) { 
            if(count==8){
            
            for (int i = 0; i < 8; ++i){
                data1[i] = data[i];
            }
            const char* array = data1;
            printf("%s\n", array);  
            unsigned char byte = GetByte(array);
            fwrite(&byte, 1, 1, f);
            //qzx = data[8];
            memset(&data, 0, sizeof(data));
            memset(&data1, 0, sizeof(data1));
            printf("%i\n",88);
            printf("%s  \n", data);  
            //data[0] = qzx;
            count=0;
            }
            if(count==9){
            for (int i = 0; i < 8; ++i){
                data1[i] = data[i];
            }
            const char* array = data1;
            printf("%s\n", array);  
            unsigned char byte = GetByte(array);
            fwrite(&byte, 1, 1, f);
            qzx = data[8];
            memset(&data, 0, sizeof(data));
            memset(&data1, 0, sizeof(data1));
            printf("%d\n",99);
            data[0] = qzx;
            printf("%s  \n", data);  
            count=1;
            }
            if(count==10){
            for (int i = 0; i < 8; ++i){
                data1[i] = data[i];
            }
            const char* array = data1;
            printf("%s  \n", array);  
            unsigned char byte = GetByte(array);
            fwrite(&byte, 1, 1, f);
            qzx1 = data[8];
            qzx2 = data[9];
            memset(&data, 0, sizeof(data));
            memset(&data1, 0, sizeof(data1));
            printf("%d\n", 55);
            data[0] = qzx1;
            data[1] = qzx2;
            printf("%s\n", data);             
            count=2;
            }
            ch = fgetc(stream);
            //printf("%c", ch);      
            if (ch == '>'){ 
                slash=1;//РЅР°С€Р»Рё
                printf("naiden simvol\n");
                karetka=0;
                }
            if((ch == '\n')&&(slash==1)){ 
                //strcat(data, n);  
                //printf("%s\n", data);
                printf("naidena stroka\n");
                karetka=1;
                slash=0;
                continue;
                }
            if(karetka==1){             
                if(ch=='A'){
                    strcat(data, a); 
                    printf("%c\n", 'A'); 
                    //printf("%s\n", data);
                    count++;
                    count++;
                    count++;
                    //printf("%s\n", data);                          
                }
                else if(ch=='T'){
                    strcat(data, t);
                    printf("%c\n", 'T'); 
                    //printf("%s\n", data);
                    count++;
                    count++;
                    count++;
                    //printf("%s\n", data);                           
                }
                else if(ch=='G'){
                    strcat(data, g); 
                    printf("%c\n", 'G'); 
                    //printf("%s\n", data); 
                    count++;
                    count++;
                    count++;
                    //printf("%s\n", data);                          
                }
                else if(ch=='C'){
                    strcat(data, c);
                    printf("%c\n", 'C');
                    //printf("%s\n", data);                     
                    count++; 
                    count++;
                    count++;
                    //printf("%s\n", data);                           
                }
                else if(ch=='U'){
                    strcat(data, u);
                    printf("%c\n", 'U');
                    //printf("%s\n", data); 
                    count++; 
                    count++;
                    count++;
                    //printf("%s\n", data);                           
                }
                else if(ch=='\n'){
                    strcat(data, n);
                    count++;
                    count++;
                    count++; 
                    //printf("%s\n", data);                           
                }
            }
        }

        const char* array = data;
        printf("%s\n", data);  
        unsigned char byte = GetByte(array);
        fwrite(&byte, 1, 1, f);
         
        //int dlina = strlen(data);                     
        //printf("%i\n", dlina); 
        //char data1[dlina]; 
        //strncpy (data1, data, dlina); 
           
        //const char data1[]="111101011100110111101011110111111101100011100101110"; 
       //const size_t nData = sizeof(data1) - 1;   
       // const char* array = data1;   
       // printf("%s\n", data1);            
        /*while (array - data1 < nData){
            unsigned char byte = GetByte(array);
            fwrite(&byte, 1, 1, f);
                array += 8;
        } */
               
    fclose(stream); 
    fclose(f);
    return EXIT_SUCCESS;
    }


    else if(strcmp(argv[1], "unpack")==0){
        printf("unpack\n");
        char ch[3]; 
        char *InputPath;
        char *OutputPath;
        InputPath = argv[2];
        OutputPath = argv[3];

        FILE * stream; 
        stream = fopen(OutputPath,"w"); 
        FILE* f = fopen(InputPath, "rb");

        if (f == NULL){
            perror("input file does not exist");
            return EXIT_FAILURE;
        }
        else{
            printf("input file loaded: '%s'\n", InputPath);
        }

        if (stream == NULL){
            perror("output file does not exist");
            return EXIT_FAILURE;
        }
        else{
            printf("output file loaded: '%s'\n", InputPath);
        }

        if (feof(f)){
            perror("input file is empty");
            return EXIT_FAILURE;
        }
        else{
           printf("input file is not empty: '%s'\n", InputPath); 
        }  
        int fs = (filesize(f)+2)*8;
        char bits[fs];
        char data[fs];
        memset(bits, 0, fs*sizeof(int));
        memset(data, 0, fs*sizeof(int));
        unsigned char byte;
        while (fread(&byte, 1, 1, f) == 1)
        {
            
            strcat(data, GetBits(byte, bits));
            //strcat(data, bits);
        }
        printf("%s\n", data);
        int j;
        int i;
        int k;
        int m;
        int b=fs/3;
        printf("%i\n", fs);
        printf("%i\n", b);
        while(j<b){
            ch[0]=data[i];
            ch[1]=data[i+1];
            ch[2]=data[i+2];  
            //printf("%s\n", ch);         
            if(strcmp(ch, a)==0){
                printf("nashel a: %s\n", ch);
                fputs("A", stream);                          
            }
            else if(strcmp(ch, t)==0){
                printf("nashel t: %s\n", ch);
                fputs("T", stream);                          
            }
            else if(strcmp(ch, g)==0){
                printf("nashel g: %s\n", ch);
                fputs("G", stream);                          
            }
            else if(strcmp(ch, c)==0){
                printf("nashel c: %s\n", ch);
                fputs("C", stream);                          
            }
            else if(strcmp(ch, u)==0){
                printf("nashel u: %s\n", ch);
                fputs("U", stream);                          
            }
            else if(strcmp(ch, n)==0){
                printf("nashel karetku: %s\n", ch);
                fputs("\n", stream);                          
            }
            i+=3;
            j+=1;
            /*k+=1;
            if(k==10){
                fputs(" ", stream); 
                k=0;
                m+=1;
            }
            if(m==6){
                fputs("\n", stream); 
                m=0;
            }*/

            // printf("%i\n", i);
            // printf("%i\n", j);
        }
        
        fclose(f);
        fclose(stream);         
    }

     
    return EXIT_SUCCESS;
   
}
