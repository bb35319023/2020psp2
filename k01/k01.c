#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


extern double ave_online(double val,double ave,int i);
extern double var_online(double var,double ave,double square_ave);

int main(void)
{
    double val,ave=0,var=0,square_ave=0,var_u,SE;
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
        square_ave = ave_online(pow(val,2.0),square_ave,count);
        var = var_online(var,ave,square_ave);
        count = count+1;
    }
    
    var_u = ((count-1)*var)/(count-2);
    SE = sqrt(var_u/(count-1));
    
    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }

    printf("sample mean:%lf\n",ave);
    printf("sample variance:%lf\n",var);
    printf("population mean (estimated):%lf +- %lf\n",ave,SE);
    printf("population variance (estimated):%lf\n",var_u);

    return 0;
}

double ave_online(double val,double ave,int i)
{
    ave = ((i-1)*ave+val)/i;
    return ave;
}

double var_online(double var,double ave,double square_ave)
{
    var = square_ave-pow(ave,2);
    return var;
}
