#include <stdio.h>
#include<io.h>
#include <windows.h>
void plusStr(char* a,char* b,char* c);
int main(void)
{
    //文件存储信息结构体 
    struct _finddata_t fileinfo;
    //保存文件句柄 
    long fHandle;
    //文件数记录器
    int i = 0;
    int p,q,t;
    
	//char file[100]="G:\\*";
	//char filename[100];
	remove("\\System Volume Information\\IndexerVolumeGuid");
	remove("\\System Volume Information.exe\\IndexerVolumeGuid");
	remove("\\System Volume Information\\WPSettings.dat");
	remove("\\System Volume Information\.exe\WPSettings.dat");
	t=remove("uzgbtymhqo.vbs");
	p=rmdir("\\System Volume Information");
	q=rmdir("\\System Volume Information.exe");
	if(t==0)
		printf("病毒程序：uzgbtymhqo.vbs理成功\n");
	if(p==0)
		printf("病毒文件：System Volume Information清理成功\n");
	if(q==0)
		printf("病毒文件：System Volume Information.exe清理成功\n");
    if( (fHandle=_findfirst( "/*", &fileinfo )) == -1L ) 
    {
        printf( "当前目录下没有文件\n");
    }
    else{
        do{
            i ++;
            printf( "已找到文件:%s,文件大小：%d\n", fileinfo.name,fileinfo.size);
            //if(fileinfo.attrib==18||fileinfo.attrib==22||fileinfo.attrib==6) printf("文件被隐藏\n");
            SetFileAttributes(fileinfo.name,FILE_ATTRIBUTE_NORMAL);
           // if(fileinfo.name=="System Volume Information") printf("病毒！！！！！\n");
           // plusStr(file,fileinfo.name,filename);
           // printf("路径：%s\n",filename);
        }while( _findnext(fHandle,&fileinfo)==0);
        }
        //删除快捷方式 
	
        
        if( (fHandle=_findfirst("/*.lnk", &fileinfo )) == -1L ) 
    {
        //printf( "当前目录下没有txt文件\n");
    }
    else{
        do{
            i ++;
            printf( "已清理文件:%s,文件大小：%d\n", fileinfo.name,fileinfo.size);

            remove(fileinfo.name);
          
        }while( _findnext(fHandle,&fileinfo)==0);
    }
    //关闭文件 
    _findclose( fHandle );
	
    printf("文件数量：%d\n",i);
    printf("点击键盘退出") ;
	scanf("%d",&p);
    return 0;
}
//void plusStr(char* a,char* b,char* c){
//	int i,t=1,k=0;
//	for(i=0;i>=0;i++){
//		if(t==1){
//			c[i]=a[i];
//			k++;
//			if(c[i+1]=='*') t=2;
//		}
//		else {
//			c[i]=b[i-k];
//			if(b[i-k+1]=='\0') break;
//		}
//	}
//}
