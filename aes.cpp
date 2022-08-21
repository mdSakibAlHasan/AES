#include<bits/stdc++.h>
using namespace std;


char s_box[16][16][3] = {"63","7C","77","7B","F2","6B","6F","C5","30","01","67","2B","FE","D7","AB","76",
"CA","82","C9","7D","FA","59","47","F0","AD","D4","A2","AF","9C","A4","72","C0",
"B7","FD","93","26","36","3F","F7","CC","34","A5","E5","F1","71","D8","31","15",
"04","C7","23","C3","18","96","05","9A","07","12","80","E2","EB","27","B2","75",
"09","83","2C","1A","1B","6E","5A","A0","52","3B","D6","B3","29","E3","2F","84",
"53","D1","00","ED","20","FC","B1","5B","6A","CB","BE","39","4A","4C","58","CF",
"D0","EF","AA","FD","43","4D","33","85","45","F9","02","7F","50","3C","9F","A8",
"51","A3","40","8F","92","9D","38","F5","BC","B6","DA","21","10","FF","F3","D2",
"CD","0C","13","EC","5F","97","44","17","C4","A7","7E","3D","64","5D","19","73",
"60","81","4F","DC","22","2A","90","88","46","EE","B8","14","DE","5E","0B","DB",
"E0","32","3A","0A","49","06","24","5C","C2","D3","AC","62","91","95","E4","79",
"E7","C8","37","6D","8D","D5","4E","A9","6C","56","F4","EA","65","7A","AE","08",
"BA","78","25","2E","1C","A6","B4","C6","E8","DD","74","1F","4B","BD","8B","8A",
"70","3E","B5","66","48","03","F6","0E","61","35","57","B9","86","C1","1D","9E",
"E1","F8","98","11","69","D9","8E","94","9B","1E","87","E9","CE","55","28","DF",
"8C","A1","89","0D","BF","E6","42","68","41","99","2D","0F","B0","54","BB","16"};

char inverse_s_box[16][16][3] = {"52","09","6A","D5","30","36","A5","38","BF","40","A3","9E","81","F3","D7","FB",
"7C","E3","39","82","9B","2F","FF","87","34","8E","43","44","C4","DE","E9","CB",
"54","7B","94","32","A6","C2","23","3D","EE","4C","95","0B","42","FA","C3","4E",
"08","2E","A1","66","28","D9","24","B2","76","5B","A2","49","6D","8B","D1","25",
"72","F8","F6","64","86","68","98","16","D4","A4","5C","CC","5D","65","B6","92",
"6C","70","48","50","FD","ED","B9","DA","5E","15","46","57","A7","8D","9D","84",
"90","D8","AB","00","8C","BC","D3","0A","F7","E4","58","05","B8","B3","45","06",
"D0","2C","1E","8F","CA","3F","0F","02","C1","AF","BD","03","01","13","8A","6B",
"3A","91","11","41","4F","67","DC","EA","97","F2","CF","CE","F0","B4","E6","73",
"96","AC","74","22","E7","AD","35","85","E2","F9","37","E8","1C","75","DF","6E",
"47","F1","1A","71","1D","29","C5","89","6F","B7","62","0E","AA","18","BE","1B",
"FC","56","3E","4B","C6","D2","79","20","9A","DB","C0","FE","78","CD","5A","F4",
"1F","DD","A8","33","88","07","C7","31","B1","12","10","59","27","80","EC","5F",
"60","51","7F","A9","19","B5","4A","0D","2D","E5","7A","9F","93","C9","9C","EF",
"A0","E0","3B","4D","AE","2A","F5","B0","C8","EB","BB","3C","83","53","99","61",
"17","2B","04","7E","BA","77","D6","26","E1","69","14","63","55","21","0C","7D"};


char m2[16][16][3] = {"00","02","04","06","08","0A","0C","0E","10","12","14","16","18","1A","1C","1E",
"20","22","24","26","28","2A","2C","2E","30","32","34","36","38","3A","3C","3E",
"40","42","44","46","48","4A","4C","4E","50","52","54","56","58","5A","5C","5E",
"60","62","64","66","68","6A","6C","6E","70","72","74","76","78","7A","7C","7E",
"80","82","84","86","88","8A","8C","8E","90","92","94","96","98","9A","9C","9E",
"A0","A2","A4","A6","A8","AA","AC","AE","B0","B2","B4","B6","B8","BA","BC","BE",
"C0","C2","C4","C6","C8","CA","CC","CE","D0","D2","D4","D6","D8","DA","DC","DE",
"E0","E2","E4","E6","E8","EA","EC","EE","F0","F2","F4","F6","F8","FA","FC","FE",
"1B","19","1F","1D","13","11","17","15","0B","09","0F","0D","03","01","07","05",
"3B","39","3F","3D","33","31","37","35","2B","29","2F","2D","23","21","27","25",
"5B","59","5F","5D","53","51","57","55","4B","49","4F","4D","43","41","47","45",
"7B","79","7F","7D","73","71","77","75","6B","69","6F","6D","63","61","67","65",
"9B","99","9F","9D","93","91","97","95","8B","89","8F","8D","83","81","87","85",
"BB","B9","BF","BD","B3","B1","B7","B5","AB","A9","AF","AD","A3","A1","A7","A5",
"DB","D9","DF","DD","D3","D1","D7","D5","CB","C9","CF","CD","C3","C1","C7","C5",
"FB","F9","FF","FD","F3","F1","F7","F5","EB","E9","EF","ED","E3","E1","E7","E5"};

char m3[16][16][3] = {"00","03","06","05","0C","0F","0A","09","18","1B","1E","1D","14","17","12","11",
"30","33","36","35","3C","3F","3A","39","28","2B","2E","2D","24","27","22","21",
"60","63","66","65","6C","6F","6A","69","78","7B","7E","7D","74","77","72","71",
"50","53","56","55","5C","5F","5A","59","48","4B","4E","4D","44","47","42","41",
"C0","C3","C6","C5","CC","CF","CA","C9","D8","DB","DE","DD","D4","D7","D2","D1",
"F0","F3","F6","F5","FC","FF","FA","F9","E8","EB","EE","ED","E4","E7","E2","E1",
"A0","A3","A6","A5","AC","AF","AA","A9","B8","BB","BE","BD","B4","B7","B2","B1",
"90","93","96","95","9C","9F","9A","99","88","8B","8E","8D","84","87","82","81",
"9B","98","9D","9E","97","94","91","92","83","80","85","86","8F","8C","89","8A",
"AB","A8","AD","AE","A7","A4","A1","A2","B3","B0","B5","B6","BF","BC","B9","BA",
"FB","F8","FD","FE","F7","F4","F1","F2","E3","E0","E5","E6","EF","EC","E9","EA",
"CB","C8","CD","CE","C7","C4","C1","C2","D3","D0","D5","D6","DF","DC","D9","DA",
"5B","58","5D","5E","57","54","51","52","43","40","45","46","4F","4C","49","4A",
"6B","68","6D","6E","67","64","61","62","73","70","75","76","7F","7C","79","7A",
"3B","38","3D","3E","37","34","31","32","23","20","25","26","2F","2C","29","2A",
"0B","08","0D","0E","07","04","01","02","13","10","15","16","1F","1C","19","1A"}; 

char m9[16][16][3] = {"00","09","12","1B","24","2D","36","3F","48","41","5A","53","6C","65","7E","77",
"90","99","82","8B","B4","BD","A6","AF","D8","D1","CA","C3","FC","F5","EE","E7",
"3B","32","29","20","1F","16","0D","04","73","7A","61","68","57","5E","45","4C",
"AB","A2","B9","B0","8F","86","9D","94","E3","EA","F1","F8","C7","CE","D5","DC",
"76","7F","64","6D","52","5B","40","49","3E","37","2C","25","1A","13","08","01",
"E6","EF","F4","FD","C2","CB","D0","D9","AE","A7","BC","B5","8A","83","98","91",
"4D","44","5F","56","69","60","7B","72","05","0C","17","1E","21","28","33","3A",
"DD","D4","CF","C6","F9","F0","EB","E2","95","9C","87","8E","B1","B8","A3","AA",
"EC","E5","FE","F7","C8","C1","DA","D3","A4","AD","B6","BF","80","89","92","9B",
"7C","75","6E","67","58","51","4A","43","34","3D","26","2F","10","19","02","0B",
"D7","DE","C5","CC","F3","FA","E1","E8","9F","96","8D","84","BB","B2","A9","A0",
"47","4E","55","5C","63","6A","71","78","0F","06","1D","14","2B","22","39","30",
"9A","93","88","81","BE","B7","AC","A5","D2","DB","C0","C9","F6","FF","E4","ED",
"0A","03","18","11","2E","27","3C","35","42","4B","50","59","66","6F","74","7D",
"A1","A8","B3","BA","85","8C","97","9E","E9","E0","FB","F2","CD","C4","DF","D6",
"31","38","23","2A","15","1C","07","0E","79","70","6B","62","5D","54","4F","46"};

char m11[16][16][3] = {"00","0B","16","1D","2C","27","3A","31","58","53","4E","45","74","7F","62","69",
"B0","BB","A6","AD","9C","97","8A","81","E8","E3","FE","F5","C4","CF","D2","D9",
"7B","70","6D","66","57","5C","41","4A","23","28","35","3E","0F","04","19","12",
"CB","C0","DD","D6","E7","EC","F1","FA","93","98","85","8E","BF","B4","A9","A2",
"F6","FD","E0","EB","DA","D1","CC","C7","AE","A5","B8","B3","82","89","94","9F",
"46","4D","50","5B","6A","61","7C","77","1E","15","08","03","32","39","24","2F",
"8D","86","9B","90","A1","AA","B7","BC","D5","DE","C3","C8","F9","F2","EF","E4",
"3D","36","2B","20","11","1A","07","0C","65","6E","73","78","49","42","5F","54",
"F7","FC","E1","EA","DB","D0","CD","C6","AF","A4","B9","B2","83","88","95","9E",
"47","4C","51","5A","6B","60","7D","76","1F","14","09","02","33","38","25","2E",
"8C","87","9A","91","A0","AB","B6","BD","D4","DF","C2","C9","F8","F3","EE","E5",
"3C","37","2A","21","10","1B","06","0D","64","6F","72","79","48","43","5E","55",
"01","0A","17","1C","2D","26","3B","30","59","52","4F","44","75","7E","63","68",
"B1","BA","A7","AC","9D","96","8B","80","E9","E2","FF","F4","C5","CE","D3","D8",
"7A","71","6C","67","56","5D","40","4B","22","29","34","3F","0E","05","18","13",
"CA","C1","DC","D7","E6","ED","F0","FB","92","99","84","8F","BE","B5","A8","A3"};


char m13[16][16][3] = {"00","0D","1A","17","34","39","2E","23","68","65","72","7F","5C","51","46","4B",
"D0","DD","CA","C7","E4","E9","FE","F3","B8","B5","A2","AF","8C","81","96","9B",
"BB","B6","A1","AC","8F","82","95","98","D3","DE","C9","C4","E7","EA","FD","F0",
"6B","66","71","7C","5F","52","45","48","03","0E","19","14","37","3A","2D","20",
"6D","60","77","7A","59","54","43","4E","05","08","1F","12","31","3C","2B","26",
"BD","B0","A7","AA","89","84","93","9E","D5","D8","CF","C2","E1","EC","FB","F6",
"D6","DB","CC","C1","E2","EF","F8","F5","BE","B3","A4","A9","8A","87","90","9D",
"06","0B","1C","11","32","3F","28","25","6E","63","74","79","5A","57","40","4D",
"DA","D7","C0","CD","EE","E3","F4","F9","B2","BF","A8","A5","86","8B","9C","91",
"0A","07","10","1D","3E","33","24","29","62","6F","78","75","56","5B","4C","41",
"61","6C","7B","76","55","58","4F","42","09","04","13","1E","3D","30","27","2A",
"B1","BC","AB","A6","85","88","9F","92","D9","D4","C3","CE","ED","E0","F7","FA",
"B7","BA","AD","A0","83","8E","99","94","DF","D2","C5","C8","EB","E6","F1","FC",
"67","6A","7D","70","53","5E","49","44","0F","02","15","18","3B","36","21","2C",
"0C","01","16","1B","38","35","22","2F","64","69","7E","73","50","5D","4A","47",
"DC","D1","C6","CB","E8","E5","F2","FF","B4","B9","AE","A3","80","8D","9A","97"};


char m14[16][16][3] = {"00","0E","1C","12","38","36","24","2A","70","7E","6C","62","48","46","54","5A",
"E0","EE","FC","F2","D8","D6","C4","CA","90","9E","8C","82","A8","A6","B4","BA",
"DB","D5","C7","C9","E3","ED","FF","F1","AB","A5","B7","B9","93","9D","8F","81",
"3B","35","27","29","03","0D","1F","11","4B","45","57","59","73","7D","6F","61",
"AD","A3","B1","BF","95","9B","89","87","DD","D3","C1","CF","E5","EB","F9","F7",
"4D","43","51","5F","75","7B","69","67","3D","33","21","2F","05","0B","19","17",
"76","78","6A","64","4E","40","52","5C","06","08","1A","14","3E","30","22","2C",
"96","98","8A","84","AE","A0","B2","BC","E6","E8","FA","F4","DE","D0","C2","CC",
"41","4F","5D","53","79","77","65","6B","31","3F","2D","23","09","07","15","1B",
"A1","AF","BD","B3","99","97","85","8B","D1","DF","CD","C3","E9","E7","F5","FB",
"9A","94","86","88","A2","AC","BE","B0","EA","E4","F6","F8","D2","DC","CE","C0",
"7A","74","66","68","42","4C","5E","50","0A","04","16","18","32","3C","2E","20",
"EC","E2","F0","FE","D4","DA","C8","C6","9C","92","80","8E","A4","AA","B8","B6",
"0C","02","10","1E","34","3A","28","26","7C","72","60","6E","44","4A","58","56",
"37","39","2B","25","0F","01","13","1D","47","49","5B","55","7F","71","63","6D",
"D7","D9","CB","C5","EF","E1","F3","FD","A7","A9","BB","B5","9F","91","83","8D"};


char binary[16][5]={"0000","0001","0010","0011","0100","0101","0110","0111","1000","1001","1010","1011","1100","1101","1110","1111"};
char hexadecimal[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
char forward_transformation[][4] = {'2','3','1','1','1','2','3','1','1','1','2','3','3','1','1','2'};

struct sakib
{
   char data[4][3];
};

struct sakib word[44],temp_word,RC_word;

//----------------------------------------basic function--------------------


int hex_to_decimal(char hex)
{
    for(int i=0;i<16;i++){
        if(hex == hexadecimal[i]){
            return i;
        }
    }

    cout<<"Error message"<<endl;
    exit(-1);
}

void hexa_to_binary(char hex[], char binary_number[])
{
    
    strcpy(binary_number,binary[hex_to_decimal(hex[0])]);
    strcat(binary_number,binary[hex_to_decimal(hex[1])]);

}



void substitution(char hex[],char box[16][16][3])       //FOR ONE BYTE SUBSTITUITION
{
    int row = hex_to_decimal(hex[0]);
    int column = hex_to_decimal(hex[1]);

    strcpy(hex,box[row][column]);
}




//----------------------------key generation ---------------------------------------------


void input_key(char key[])
{
    char temp_key[50];
    cout<<"Input your key(16 byte take only): ";
    cin.getline(temp_key,50);
    if(strlen(temp_key)<16){
        cout<<"Your key is too small: ";
    }
    copy(temp_key,temp_key+16,key);
    cout<<"Your key is: "<<key<<endl;
}



char RC[][3] = {"00","01","02","04","08","10","20","40","80","1B","36"};

void XOR_key_generation(struct sakib *shift_word, struct sakib x)
{
    int sum[2][4];
    for(int i=0;i<4;i++){
        sum[0][i] = hex_to_decimal(shift_word->data[i][0])*16 + hex_to_decimal(shift_word->data[i][1]);
        sum[1][i] = hex_to_decimal(x.data[i][0])*16 + hex_to_decimal(x.data[i][1]);
    }


    for(int i=0;i<4;i++){
        sum[0][i] = sum[0][i]^sum[1][i];

        shift_word->data[i][1] = hexadecimal[sum[0][i]%16];
        shift_word->data[i][0] = hexadecimal[sum[0][i]/16];
    }
    
}

void Rotword(struct sakib *shift_word)
{
    char temp_char[3];
    
    strcpy(temp_char,shift_word->data[0]);
    for(int i=0;i<3;i++){
        strcpy(shift_word->data[i],shift_word->data[i+1]);
    }
    strcpy(shift_word->data[3],temp_char);

}


void subWord(struct sakib *shif_word)
{
    for(int i=0;i<4;i++){
        substitution(shif_word->data[i],s_box);
    }
}

void key_generation(char key_matrix[16][3])
{
    //key is already in hexadecimnal format

    for(int i=0;i<4;i++){               //copy original key
        for(int j=0;j<4;j++){
            strcpy(word[i].data[j], key_matrix[(i*4)+j]);
        }
    }

    for(int i=4;i<44;i++){
        temp_word = word[i-1];
        if(i%4 == 0){
            Rotword(&temp_word);
            subWord(&temp_word);
            strcpy(RC_word.data[0],RC[i/4]);
            for(int i=1;i<4;i++){
                strcpy(RC_word.data[i],"00");
            }
            XOR_key_generation(&temp_word,RC_word);
        }

        word[i] = word[i-4];
        XOR_key_generation(&word[i],temp_word);
        
    }

}




//--------------------------------------Encryption code start---------------------------------\



void substitution(char box[16][16][3],char message[][3])            //FOR 16 BYTE SUBSTITUTION
{
    for(int i=0;i<16;i++){
        substitution(message[i],box);
    }    
}



void XOR_value(char temp[4][3])
{
    //xor four value a^b here a,b are decimal ; result will dcimal and store temp[0]
    int sum[4];
    for(int i=0;i<4;i++){
        sum[i] = hex_to_decimal(temp[i][0])*16 + hex_to_decimal(temp[i][1]);
    }

    for(int i=1;i<4;i++){
        sum[0] = sum[0]^sum[i];
    }

    temp[0][1] = hexadecimal[sum[0]%16];      //conver decimal to hexadecimal
    temp[0][0] = hexadecimal[sum[0]/16];

}



void mix_column(char matrix[16][3])
{
    int fixed_matrix[][4]={2,3,1,1,
                        1,2,3,1,
                        1,1,2,3,
                        3,1,1,2};
    char new_matrix[4][4][3];

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            char temp[4][3];
            for(int k=0;k<4;k++){
                strcpy(temp[k],matrix[(k*4)+j]);
                if(fixed_matrix[i][k] == 2){
                    substitution(temp[k],m2);
                }
                else if(fixed_matrix[i][k] == 3){
                    substitution(temp[k],m3);
                }
            }

            XOR_value(temp);
            strcpy(new_matrix[i][j],temp[0]);
        }
    }

    for(int i=0;i<16;i++){                          //copy to original array
        strcpy(matrix[i],new_matrix[i/4][i%4]);
    }

}





int inverse_shift_row_array[] = {0,1,2,3,7,4,5,6,10,11,8,9,13,14,15,12};
int shift_swap_array[16]={0,1,2,3,5,6,7,4,10,11,8,9,15,12,13,14};

void shift_row(char matrix[16][3], int swap_array[])
{
    char temp_array[16][3];
    

    for(int k=0;k<16;k++){
        strcpy(temp_array[k],matrix[k]);
    }


    for(int i=0;i<16;i++){
        if(i != swap_array[i]){
          strcpy(matrix[i], temp_array[swap_array[i]]);
        } 
    }
}



void add_round_key(char matrix[16][3], int start)
{
    int sum[2][16];
    for(int i=0;i<16;i++){
        sum[0][i] = hex_to_decimal(matrix[i][0])*16 + hex_to_decimal(matrix[i][1]);
        sum[1][i] = hex_to_decimal(word[(i%4)+start].data[(i/4)][0])*16 + hex_to_decimal(word[(i%4)+start].data[(i/4)][1]);
    }


    for(int i=0;i<16;i++){
        sum[0][i] = sum[0][i]^sum[1][i];

        matrix[i][1] = hexadecimal[sum[0][i]%16];
        matrix[i][0] = hexadecimal[sum[0][i]/16];
    }
    
}


void encryption(char message[16][3])
{
    add_round_key(message,0);
    for(int i=0;i<9;i++){
        substitution(s_box,message);
        shift_row(message,shift_swap_array);
        mix_column(message);
        add_round_key(message,(i+1)*4);
    }
    substitution(s_box,message);
    shift_row(message,shift_swap_array);
    add_round_key(message,40);
    
}

void write_in_file(char message[16][3],string file_name)
{
    int k;
    ofstream fin;
    fin.open(file_name,ios::app);
    if(!fin.is_open()){
        cout<<"File can't open "<<endl;
        exit(0);
    }
    
    for(int i=0;i<16;i++){
        fin<<message[i][0]<<message[i][1];
    }
    
    fin.close();
}


void encryption_input(string in_file_name, string out_file_name)
{
     char key[17],key_block[16][3],byte,message[16][3];
    cout<<"Input your key(16 byte take only): ";
    cin.getline(key, 17);
    cout<<"Your key is: "<<key<<endl;

    for(int i=0;i<16;i++){
        key_block[i][1] = hexadecimal[(int)key[i]%16];      //conver decimal to hexadecimal
        key_block[i][0] = hexadecimal[(int)key[i]/16];
    }

    key_generation(key_block);

    ifstream input_file(in_file_name);
    if(!input_file.is_open()){
        cout<<in_file_name<<" file can't open"<<endl;
        exit(0);
    }

    //read from file
    int counter=0;
    while(input_file.get(byte)){
        message[counter][1] = hexadecimal[(int)byte%16];      //conver decimal to hexadecimal
        message[counter][0] = hexadecimal[(int)byte/16];
        
        if(++counter == 16){ 
            encryption(message);                           //this function is encryption or depryption
            write_in_file(message,out_file_name);
            counter = 0;
        }
    }

    //fill rest of the 16 byte with 00
    // for( ;counter<16;counter++){
    //     message[counter][0] = '0';
    //     message[counter][1] = 'A';
    // }
    // encryption(message);                              //this function is encryption or depryption
    // write_in_file(message,out_file_name);
}



//--------------------------------Decryption input--------------------------------


void inverse_mix_column(char matrix[16][3])
{
    int fixed_matrix[][4]={14,11,13,9,
                            9,14,11,13,
                            13,9,14,11,
                            11,13,9,14};
    char new_matrix[4][4][3];

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            char temp[4][3];
            for(int k=0;k<4;k++){
                strcpy(temp[k],matrix[(k*4)+j]);
                if(fixed_matrix[i][k] == 9){
                    substitution(temp[k],m9);
                }
                else if(fixed_matrix[i][k] == 11){
                    substitution(temp[k],m11);
                }
                else if(fixed_matrix[i][k] == 13){
                    substitution(temp[k],m13);
                }
                else if(fixed_matrix[i][k] == 14){
                    substitution(temp[k],m14);
                }
            }

            XOR_value(temp);
            strcpy(new_matrix[i][j],temp[0]);
        }
    }

    for(int i=0;i<16;i++){                          //copy to original array
        strcpy(matrix[i],new_matrix[i/4][i%4]);
    }

}




void decryption(char message[16][3])
{
    add_round_key(message,40);
    for(int i=9;i>0;i--){
        shift_row(message,inverse_shift_row_array);
        substitution(inverse_s_box,message);
        add_round_key(message,i*4);
        inverse_mix_column(message);
    }
    shift_row(message,inverse_shift_row_array);
    substitution(inverse_s_box,message);
    add_round_key(message,0);

}





void restore_byte(char message[16][3],string file_name)
{
    int k;
    ofstream fin;
    fin.open(file_name,ios::app);
    if(!fin.is_open()){
        cout<<"File can't open "<<endl;
        exit(0);
    }
    
    for(int i=0;i<16;i++){
        k = hex_to_decimal(message[i][0])*16 + hex_to_decimal(message[i][1]);
        fin<<(char)k;
    }

    fin.close();
}



void decryption_input(string in_file_name, string out_file_name)
{
     char key[17],key_block[16][3],byte,message[16][3];
    cout<<"Input your key(16 byte take only): ";
    cin.getline(key, 17);
    cout<<"Your key is: "<<key<<endl;

    for(int i=0;i<16;i++){
        key_block[i][1] = hexadecimal[(int)key[i]%16];      //conver decimal to hexadecimal
        key_block[i][0] = hexadecimal[(int)key[i]/16];
    }

    key_generation(key_block);

    ifstream input_file(in_file_name);
    if(!input_file.is_open()){
        cout<<in_file_name<<" file can't open"<<endl;
        exit(0);
    }

    //read from file
    int counter=0;
    while(input_file.get(byte)){
        message[counter][0] = byte; 
        input_file.get(byte);
        message[counter][1] = byte;

        if(++counter == 16){ 
            decryption(message);                           //this function is encryption or depryption
            restore_byte(message,out_file_name);
            counter = 0;
        }
    }

}




int main()
{
    //char key[17];
    encryption_input("input.txt","another.txt");
    
    decryption_input("another.txt","output.txt");
}