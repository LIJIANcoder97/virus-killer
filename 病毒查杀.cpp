#include <stdio.h>
#include<io.h>
#include <windows.h>
void plusStr(char* a,char* b,char* c);
int main(void)
{
    //�ļ��洢��Ϣ�ṹ�� 
    struct _finddata_t fileinfo;
    //�����ļ���� 
    long fHandle;
    //�ļ�����¼��
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
		printf("��������uzgbtymhqo.vbs��ɹ�\n");
	if(p==0)
		printf("�����ļ���System Volume Information����ɹ�\n");
	if(q==0)
		printf("�����ļ���System Volume Information.exe����ɹ�\n");
    if( (fHandle=_findfirst( "/*", &fileinfo )) == -1L ) 
    {
        printf( "��ǰĿ¼��û���ļ�\n");
    }
    else{
        do{
            i ++;
            printf( "���ҵ��ļ�:%s,�ļ���С��%d\n", fileinfo.name,fileinfo.size);
            //if(fileinfo.attrib==18||fileinfo.attrib==22||fileinfo.attrib==6) printf("�ļ�������\n");
            SetFileAttributes(fileinfo.name,FILE_ATTRIBUTE_NORMAL);
           // if(fileinfo.name=="System Volume Information") printf("��������������\n");
           // plusStr(file,fileinfo.name,filename);
           // printf("·����%s\n",filename);
        }while( _findnext(fHandle,&fileinfo)==0);
        }
        //ɾ����ݷ�ʽ 
	
        
        if( (fHandle=_findfirst("/*.lnk", &fileinfo )) == -1L ) 
    {
        //printf( "��ǰĿ¼��û��txt�ļ�\n");
    }
    else{
        do{
            i ++;
            printf( "�������ļ�:%s,�ļ���С��%d\n", fileinfo.name,fileinfo.size);

            remove(fileinfo.name);
          
        }while( _findnext(fHandle,&fileinfo)==0);
    }
    //�ر��ļ� 
    _findclose( fHandle );
	
    printf("�ļ�������%d\n",i);
    printf("��������˳�") ;
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
