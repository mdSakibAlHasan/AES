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

char binary[16][5]={"0000","0001","0010","0011","0100","0101","0110","0111","1000","1001","1010","1011","1100","1101","1110","1111"};
char hexadecimal[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
char forward_transformation[][4] = {'2','3','1','1','1','2','3','1','1','1','2','3','3','1','1','2'};

struct sakib
{
   char data[4][3];
};

struct sakib word[44],temp_word,RC_word;

void printer_check(char ma[16][3])
{
    cout<<endl;
    for(int i=0;i<16;i++){
        cout<<ma[i]<<" ";
    }
    cout<<endl;
}


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



void substitution_byte(char hex[])
{
    int row = hex_to_decimal(hex[0]);
    int column = hex_to_decimal(hex[1]);

    strcpy(hex,s_box[row][column]);
}

void substitution(char hex[],char m[16][16][3])
{
    int row = hex_to_decimal(hex[0]);
    int column = hex_to_decimal(hex[1]);

    strcpy(hex,m[row][column]);
}


void inverse_substitution_byte(char hex[])
{
    int row = hex_to_decimal(hex[0]);
    int column = hex_to_decimal(hex[1]);

    strcpy(hex,inverse_s_box[row][column]);
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


void shift_row(char matrix[16][3])
{
    char temp_array[16][3];
    int swap_array[16]={0,1,2,3,5,6,7,4,10,11,8,9,15,12,13,14};

    for(int k=0;k<16;k++){
        strcpy(temp_array[k],matrix[k]);
    }


    for(int i=0;i<16;i++){
        if(i != swap_array[i]){
          strcpy(matrix[i], temp_array[swap_array[i]]);
        } 
    }
}


void input(char message[])
{
    cin.getline(message, 17);
    //cin.getline(key, 17);



}



void substitution_step(char matrix[16][3])
{
    for(int i=0;i<16;i++){
        substitution_byte(matrix[i]);
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
        //cout<<sum[0][i]<<" "<<sum[0][i]<<endl;
        sum[0][i] = sum[0][i]^sum[1][i];

        matrix[i][1] = hexadecimal[sum[0][i]%16];
        matrix[i][0] = hexadecimal[sum[0][i]/16];
    }
    
}


void encryption(char message[16][3])
{
    //printer_check(message);
    
    add_round_key(message,0);
    //printer_check(message);
    for(int i=0;i<9;i++){
        substitution_step(message);
        shift_row(message);
        mix_column(message);
        add_round_key(message,(i+1)*4);
    }
    substitution_step(message);
    shift_row(message);
    add_round_key(message,40);
    
    cout<<"After last step"<<endl;
    printer_check(message);
}

void substitution(char message[])
{
    //for later input section
    input(message);
    char block[16][3];
    int remainder,result;

    for(int i=0;i<16;i++){
        block[i][1] = hexadecimal[(int)message[i]%16];      //conver decimal to hexadecimal
        block[i][0] = hexadecimal[(int)message[i]/16];

                //substitution byte

        substitution_byte(block[i]);
    }

    printer_check(block);
    shift_row(block);
    printer_check(block);
    mix_column(block);
    printer_check(block);
}






//----------------------------key generation ---------------------------------------------


char RC[][3] = {"00","01","02","04","08","10","20","40","80","1B","36"};

void check(struct sakib a)
{
    for(int i=0;i<4;i++){
        cout<<a.data[i]<<" ";
    }
    cout<<endl;
}


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
        substitution_byte(shif_word->data[i]);
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

    // for(int i=0;i<44;i++){
    //     for(int j=0;j<4;j++){
    //         cout<<word[i].data[j]<<" ";
    //     }
    //     cout<<endl;
    // }

}



int main()
{

    char message[16][3]={"01","89","FE","76","23","AB","DC","54","45","CD","BA","32","67","EF","98","10"};
    char message2[16][3]={"54","77","6F","20","4F","6E","65","20","4E","69","6E","65","20","54","77","6F"};
    char key_matrix[16][3]={"54","68","61","74","73","20","6D","79","20","4B","75","6E","67","20","46","75"};
        char keymatrix[16][3]={"0F","15","71","C9","47","D9","E8","59","0C","B7","AD","D6","AF","7F","67","98"};
    //substitution(message);

    key_generation(keymatrix);

    encryption(message);
}