#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

extern double ave_online(double val,double ave,int i);
extern double square_ave_online(double val,double square_ave,int i);
extern double var_online(double var,double ave,double square_ave);

int main(void)
{
    double val,ave=0,var=0,square_ave=0,var_u;
    char fname[FILENAME_MAX];
    char buf[256];
    int count;
    FILE* fp;

    printf("input the filename of sample:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1] = '\0';
    printf("the filename of sample: %s\n",fname);

    fp = fopen(fname,"r");
    if(fp==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }
    
    count = 1;
    while(fgets(buf,sizeof(buf),fp) != NULL){
        sscanf(buf,"%lf",&val);
        ave = ave_online(val,ave,count);
        square_ave = square_ave_online(val,square_ave,count);
        count = count+=1;
    }
    
    var = var_online(var,ave,square_ave);
    var_u = ((count-1)*var)/(count-2);
    
    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }

    printf("average:%lf\n",ave);
    printf("variance:%lf\n",var_u);


    return 0;


}

double ave_online(double val,double ave,int i)
{
    ave = ((i-1)*ave+val)/i;
    return ave;
}

double square_ave_online(double val,double square_ave,int i)
{
    square_ave = ((i-1)*square_ave+pow(val,2))/i;
    return square_ave;
}

double var_online(double var,double ave,double square_ave)
{
    var = square_ave-pow(ave,2);
    return var;
}
