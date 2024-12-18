#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

struct userAttributes
{
    int ID;
    char name[100];
    int age;
};

void createNewUser(FILE *file){
    struct userAttributes user;
    
    printf("\nEnter your ID:\n");
    scanf("%d",&user.ID);
    getchar();
    printf("\nEnter your name:\n");
    scanf("%[^\n]",&user.name);
    printf("\nEnter your age:\n");
    scanf("%d",&user.age);

    // setting file pointer to end
    fseek(file,0,SEEK_END);
    fwrite(&user,sizeof(user),1,file);

    printf("\n New user uccessfully created. \n");

}

void readUserInformation(FILE *file){
    struct userAttributes user;

    // setting file pointer to start
    fseek(file, 0, SEEK_SET);
    

    int count=1;
    while (fread(&user,sizeof(user),1,file))
    {   
        printf("\t\tUser-%d\n",count++);
        printf("ID=%d\nName=%s\nAge=%d\n\n",user.ID,user.name,user.age);
    }

}

void deleteUser(FILE *file){
    int idToDelete;
    printf("Enter user's ID you want to delete: ");
    scanf("%d", &idToDelete);

    FILE *temp = fopen("temp.txt", "w");
    struct userAttributes user;

    // setting file pointer to start
    fseek(file, 0, SEEK_SET);
    

    bool flag=false;

    while (fread(&user, sizeof(user), 1, file)) {
        if (user.ID == idToDelete) {
            flag = true;
            //don't add this  
        } else {
            fwrite(&user, sizeof(user), 1, temp);
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

void updateExistingUser(FILE *file){
    int idToUpdate;
    printf("Enter user's ID you want to update: ");
    scanf("%d", &idToUpdate);
    FILE *temp = fopen("temp.txt", "w");
    struct userAttributes user;

    // setting file pointer to start
    fseek(file, 0, SEEK_SET);
    

    bool flag=false;

    while (fread(&user, sizeof(user), 1, file)) {
        if (user.ID == idToUpdate) {

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
                    getchar();
                    printf("\nEnter new Name:");
                    scanf("%[^\n]",&newName);

                    strcpy(user.name,newName);
                    break;
                case 2:
                    printf("\nEnter new Age:");
                    scanf("%d",&newAge);

                    user.age=newAge;
                    break;
                case 3:
                    getchar();
                    printf("\nEnter new Name:");
                    scanf("%[^\n]",&newName);
                    printf("\nEnter new Age:");
                    scanf("%d",&newAge);

                    strcpy(user.name,newName);
                    user.age=newAge;

                    break;
                default:
                    printf("Invalid. Choose from above options only.\n");
                    break;

            }


            flag = true;
              
        } 
            fwrite(&user, sizeof(user), 1, temp);
        
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
void getInput(FILE *file){
    int choice;
    while(true){

        printf("Enter 0 to Exit\n");
        printf("Enter 1 to Create User\n");
        printf("Enter 2 to Delete User\n");
        printf("Enter 3 to Update User\n");
        printf("Enter 4 to Read Users\n");

        scanf("%d",&choice);

        switch(choice){
            case 0:
                fclose(file);
                exit(0);
                break;
            case 1:
                createNewUser(file);
                break;
            case 2:
                deleteUser(file);
                file = fopen("users.txt", "r+");
                break;
            case 3:
                updateExistingUser(file);
                file = fopen("users.txt", "r+");
                break;
            case 4:
                readUserInformation(file);
                break;
            default:
                printf("Invalid Choice , select from above listed choices\n");
        } 
        
    }

}
int main(){
    FILE *file=fopen("users.txt","r+");

    if(file==NULL){
        file=fopen("users.txt","w+");
    }

    getInput(file);
    
    return 0;
}
