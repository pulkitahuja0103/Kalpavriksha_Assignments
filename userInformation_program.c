#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

struct MyStructure
{
    int ID;
    char name[100];
    int age;
};

void create(FILE *file){
    struct MyStructure s;
    printf("\nEnter your ID:\n");
    scanf("%d",&s.ID);
    printf("\nEnter your name:\n");
    scanf("%s",&s.name);
    printf("\nEnter your age:\n");
    scanf("%d",&s.age);

    // setting file pointer to end
    fseek(file,0,SEEK_END);
    fwrite(&s,sizeof(s),1,file);

    printf("\n user created. \n");

}

void read(FILE *file){
    struct MyStructure s;

    // setting file pointer to start
    fseek(file, 0, SEEK_SET);
    

    int count=1;
    while (fread(&s,sizeof(s),1,file))
    {   
        printf("\t\tUser-%d\n",count++);
        printf("ID=%d\nName=%s\nAge=%d\n\n",s.ID,s.name,s.age);
    }

}

void deleteUser(FILE *file){
    int idToDelete;
    printf("Enter user's ID you want to delete: ");
    scanf("%d", &idToDelete);

    FILE *temp = fopen("temp.txt", "w");
    struct MyStructure s;

    // setting file pointer to start
    fseek(file, 0, SEEK_SET);
    

    bool flag=false;

    while (fread(&s, sizeof(s), 1, file)) {
        if (s.ID == idToDelete) {
            flag = true;
            //don't add this  
        } else {
            fwrite(&s, sizeof(s), 1, temp);
        }
    }

    fclose(temp);
    fclose(file);

    if (flag==true) {
        remove("users.txt"); 
        rename("temp.txt", "users.txt");
        printf("user deleted\n");
    } else {
        remove("temp.txt");
        printf("\n user not found. \n");
    }

}

void update(FILE *file){
    int idToUpdate;
    printf("Enter user's ID you want to update: ");
    scanf("%d", &idToUpdate);
    FILE *temp = fopen("temp.txt", "w");
    struct MyStructure s;

    // setting file pointer to start
    fseek(file, 0, SEEK_SET);
    

    bool flag=false;

   

    while (fread(&s, sizeof(s), 1, file)) {
        if (s.ID == idToUpdate) {

            char newName[100];
            int newAge;

            int option;
            printf("\nWhat you want to update:\n");
            printf("Enter 1 for name\n");
            printf("Enter 2 for age\n");
            printf("Enter 3 for both name and age\n");
            scanf("%d",&option);
            switch(option){
                case 1:
                    printf("\nEnter new Name:");
                    scanf("%s",&newName);

                    strcpy(s.name,newName);
                    break;
                case 2:
                    printf("\nEnter new Age:");
                    scanf("%d",&newAge);

                    s.age=newAge;
                    break;
                case 3:
                    printf("\nEnter new Name:");
                    scanf("%s",&newName);
                    printf("\nEnter new Age:");
                    scanf("%d",&newAge);

                    strcpy(s.name,newName);
                    s.age=newAge;

                    break;
                default:
                    printf("Invalid. Choose from above options only.\n");
                    break;

            }


            flag = true;
              
        } 
            fwrite(&s, sizeof(s), 1, temp);
        
    }

    
    fclose(temp);
    fclose(file);
    
    if (flag) {
        remove("users.txt"); 
        rename("temp.txt", "users.txt");
        printf("user updated\n");
    } else {
        remove("temp.txt");
        printf("\n user not found. \n");
    }


}

int main(){
    FILE *file=fopen("users.txt","r+");

    if(file==NULL){
        file=fopen("users.txt","w+");
    }

    int val;
    while(true){

        printf("Enter 0 to Exit\n");
        printf("Enter 1 to Create User\n");
        printf("Enter 2 to Delete User\n");
        printf("Enter 3 to Update User\n");
        printf("Enter 4 to Read Users\n");

        scanf("%d",&val);

        switch(val){
            case 0:
                fclose(file);
                exit(0);
                break;
            case 1:
                create(file);
                break;
            case 2:
                deleteUser(file);
                file = fopen("users.txt", "r+");
                break;
            case 3:
                update(file);
                file = fopen("users.txt", "r+");
                break;
            case 4:
                read(file);
                break;
            default:
                printf("Invalid , select from above choices\n");
        }

        
    }

    return 0;
}
