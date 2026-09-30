#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_MARKS 100
#define MAX_AGE 100
#define PF printf
#define SF scanf
struct student
{
        int id;
        char name[20];
        int age;
        float marks;
};
struct student *s;
int c=0;
void add_student();
void display_student();
void search_student();
void update_student();
void delete_student();
void sort_student();
void save_students(char **argv);
void load_students(char **argv);
void search_name();
void highest_marks();
void lowest_marks();
void average_marks();
void pass_fail();
void sort_name();
void sort_id();
int main(int argc,char **argv)
{
        if(argc<2)
        {
                PF("usage:./a.out fname\n");
                return 0;
        }
l:
        printf("Student Management System\n");
        printf("enter 1 to add student\n");
        printf("enter 2 to display students\n");
        printf("enter 3 to search student\n");
        printf("enter 4 to update student\n");
        printf("enter 5 to delete student\n");
        printf("enter 6 to sort students\n");
        printf("enter 7 for save students\n");
        printf("enter 8 for load students\n");
        printf("enter 9 for search students by name\n");
        printf("enter 10 for exit\n");
        printf("enter 11 for total students\n");
        printf("enter 12 for finding highest marks\n");
        printf("enter 13 for finding lowest marks \n");
        printf("enter 14 for finding average \n");
        printf("enter 15 for pass/fail report \n");
        printf("enter 16 for sort by name \n");
        printf("enter 17 for sort by id \n");
        printf("\n");
        int op;
        printf("enter your option:\n");
        scanf("%d",&op);
        printf("you selected option %d\n",op);
        switch(op)
        {
                case 1:printf("Add student was selected\n");
                       add_student();
                       goto l;
                case 2:printf("display students was selected\n");
                       display_student();
                       goto l;
                case 3:printf("search student by id was selected\n");
                       search_student();
                       goto l;
                case 4:printf("update student was selected\n");
                       update_student();
                       goto l;
                case 5:printf("delete student was selected\n");
                       delete_student();
                       goto l;
                case 6:printf("sort student was selected\n");
                       sort_student();
                       goto l;
                case 7:PF("save students was selected:\n");
                       save_students(argv);
                       goto l;
                case 8:PF("load students was selected:\n");
                       load_students(argv);
                       goto l;
                case 9:PF("search student by name was selected\n");
                       search_name();
                       goto l;
                case 10:printf("exit was selected\n");
                       printf("exiting program...\n");
                       free(s);
                       return 0;
                case 11:PF("TOTAL STUDENTS=%d\n",c);
                        goto l;
                case 12:PF("highest marks was selected\n");
                        highest_marks();
                        goto l;
                case 13:PF("lowest marks was selected\n");
                        lowest_marks();
                        goto l;
                case 14:PF("average marks was selected\n");
                        average_marks();
                        goto l;
                case 15:PF("pass/fail report was selected\n");
                        pass_fail();
                        goto l;
                case 16:PF("sort by name was selected\n");
                        sort_name();
                        goto l;
                case 17:PF("sort by id was selected\n");
                        sort_id();
                        goto l;
                default:printf("Invalid option\n");
                        break;
        }
        return 0;
}
void add_student()
{
        int i,n;
        printf("how many students you want to add:\n");
        scanf("%d",&n);
        if(c==0)
        {
                s=malloc(n*sizeof(struct student));
        }
        else
        {
                s=realloc(s,(c+n)*sizeof(struct student));
        }
        if(s==0)
        {
                PF("memory allocation failed\n");
                return;
        }
        for(i=0;i<n;i++)
        {
                PF("enter id:");
                SF("%d",&s[c].id);
                int i;
                for(i=0;i<c;i++)
                {
                        if(s[i].id==s[c].id)
                        {
                                PF("id already exists\n");
                                return;
                        }
                }
                PF("enter name:");
                SF(" %[^\n]",s[c].name);
                PF("enter age:");
                SF("%d",&s[c].age);
                if(s[c].age<1||s[c].age>MAX_AGE)
                {
                        printf("INVALID AGE\n");
                        return;
                }
                PF("enter marks:");
                SF("%f",&s[c].marks);
                if(s[c].marks<0||s[c].marks>MAX_MARKS)
                {
                        printf("INVALID MARKS\n");
                        return;
                }
                c++;
        }
        if(c==1)
        {
                PF("student added successfully\n");
        }
        if(c>1)
        {
                printf("students added successfully\n");
        }
}
void display_student()
{
        int i;
        if(c==0)
        {
                PF("no students available\n");
                return;
        }
        for(i=0;i<c;i++)
        {
                PF("ID:%d\n",s[i].id);
                PF("NAME:%s\n",s[i].name);
                PF("AGE:%d\n",s[i].age);
                PF("MARKS:%f\n",s[i].marks);
        }
}
void search_student()
{
        int id,i;
        PF("enter student id:\n");
        SF("%d",&id);
        for(i=0;i<c;i++)
        {
                if(id==s[i].id)
                {
                        PF("student found\n");
                        PF("Details of student\n");
                        PF("%d\n",s[i].id);
                        PF("%s\n",s[i].name);
                        PF("%d\n",s[i].age);
                        PF("%f\n",s[i].marks);
                        return;
                }
        }
        PF("student not found\n");
}
void update_student()
{
        int id,i;
        PF("enter student id which student details you want to update\n");
        SF("%d",&id);
        for(i=0;i<c;i++)
        {
                if(s[i].id==id)
                {
                        PF("enter new name:\n");
                        SF(" %[^\n]",s[i].name);
                        PF("enter new age:\n");
                        SF("%d",&s[i].age);
                        if(s[i].age<1||s[i].age>MAX_AGE)
                        {
                                PF("INVALID AGE\n");
                                return;
                        }
                        PF("enter new marks\n");
                        SF("%f",&s[i].marks);
                        if(s[i].marks<0||s[i].marks>MAX_MARKS)
                        {
                                PF("INVALID MARKS\n");
                                return;
                        }
                        PF("student updated successfully\n");
                        return;
                }
        }
        PF("student not found\n");
}
void delete_student()
{
        int id,i,j;
        PF("enter student id which student you want to delete:\n");
        SF("%d",&id);
        for(i=0;i<c;i++)
        {
                if(s[i].id==id)
                {
                        for(j=i;j<c-1;j++)
                        {
                                s[j]=s[j+1];
                        }
                        c--;
                        PF("student id deleted successfully\n");
                        return;
                }
        }
        PF("student not found\n");
}
void sort_student()
{
        int i,j;
        for(i=0;i<c-1;i++)
        {
                for(j=0;j<c-1-i;j++)
                {
                        if(s[j].marks>s[j+1].marks)
                        {
                                struct student temp;
                                temp=s[j];
                                s[j]=s[j+1];
                                s[j+1]=temp;
                        }
                }
        }
        PF("students sorted by marks\n");
}
void save_students(char **argv)
{
        FILE *fp;
        fp=fopen(argv[1],"wb");
        if(fp==0)
        {
                PF("file is not there\n");
                return;
        }
        fwrite(s,sizeof(struct student),c,fp);
        fclose(fp);
        PF("students saved successfully\n");
}
void load_students(char **argv)
{
        FILE *fp;
        long size;
        fp=fopen(argv[1],"rb");
        if(fp==0)
        {
                printf("File is not there\n");
                return;
        }
        fseek(fp,0,SEEK_END);
        size=ftell(fp);
        printf("file size is =%ld bytes\n",size);
        c=size/sizeof(struct student);
        if(s!=0)
        {
                free(s);
                s=0;
        }
        s=malloc(c*sizeof(struct student));
        if(s==0)
        {
                PF("memory allocation failed\n");
                fclose(fp);
                return;
        }
        rewind(fp);
        fread(s,sizeof(struct student),c,fp);
        fclose(fp);
        PF("students loaded successfully\n");
}
void search_name()
{
        char name[20];
        int i;
        PF("enter name:\n");
        SF(" %[^\n]",name);
        for(i=0;i<c;i++)
        {
                if(strcmp(s[i].name,name)==0)
                {
                        PF("ID:%d\n",s[i].id);
                        PF("NAME:%s\n",s[i].name);
                        PF("AGE:%d\n",s[i].age);
                        PF("MARKS:%f\n",s[i].marks);
                        return;
                }
        }
        PF("student not found\n");
}
void highest_marks()
{
        int i;
        int a=0;
        if(c==0)
        {
                PF("no students available\n");
                return;
        }
        for(i=1;i<c;i++)
        {
                if(s[i].marks>s[a].marks)
                {
                        a=i;
                }
        }
        PF("Highest marks student\n");
        PF("ID:%d\n",s[a].id);
        PF("NAME:%s\n",s[a].name);
        PF("AGE:%d\n",s[a].age);
        PF("MARKS:%f\n",s[a].marks);
}
void lowest_marks()
{
        int i;
        int a=0;
        if(c==0)
        {
                PF("no students available\n");
                return;
        }
        for(i=1;i<c;i++)
        {
                if(s[i].marks<s[a].marks)
                {
                        a=i;
                }
        }
        PF("lowest marks student\n");
        PF("ID:%d\n",s[a].id);
        PF("NAME:%s\n",s[a].name);
        PF("AGE:%d\n",s[a].age);
        PF("MARKS:%f\n",s[a].marks);
}
void average_marks()
{
        int i;
        float total=0;
        float avg;
        if(c==0)
        {
                PF("no students available\n");
                return;
        }
        for(i=0;i<c;i++)
        {
                total=total+s[i].marks;
        }
        avg=total/c;
        PF("average marks=%f\n",avg);
}
void pass_fail()
{
        int i;
        if(c==0)
        {
                PF("no students available\n");
                return;
        }
        for(i=0;i<c;i++)
        {
                PF("id=%d name=%s marks=%f",s[i].id,s[i].name,s[i].marks);
                if(s[i].marks>=40)
                {
                        PF("PASS\n");
                }
                else
                {
                        PF("FAIL\n");
                }
        }
}
void sort_name()
{
        int i,j;
        for(i=0;i<c-1;i++)
        {
                for(j=0;j<c-1-i;j++)
                {
                        if(strcmp(s[j].name,s[j+1].name)>0)
                        {
                                struct student temp;
                                temp=s[j];
                                s[j]=s[j+1];
                                s[j+1]=temp;
                        }
                }
        }
        PF("students sorted by name\n");
}
void sort_id()
{
        int i,j;
        for(i=0;i<c-1;i++)
        {
                for(j=0;j<c-1-i;j++)
                {
                        if(s[j].id>s[j+1].id)
                        {
                                struct student temp;
                                temp=s[j];
                                s[j]=s[j+1];
                                s[j+1]=temp;
                        }
                }
        }
        PF("students sorted by id\n");
}
