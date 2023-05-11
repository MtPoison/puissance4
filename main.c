#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ligne 6
#define col 7


void grille_des(int **grille){
    int count = 0, count2 = 0;
    FILE* fichier= fopen("jeu.txt","w");
    if (fichier != NULL)
    {
        for (int i = 0; i < 6; i++){
            for (int j = 0; j < 7; j++) {
                // printf("%d ",grille[i][j]);
                if (grille[i][j]==0)
                {
                    putchar('-');
                    fputc('-',fichier);
                }
                else if (grille[i][j]==1)
                {
                    putchar('X');
                    fputc('X',fichier);
                    count ++;
                }
                else if (grille[i][j]==2)
                {
                    putchar('O');
                    fputc('O',fichier);
                    count2 ++;
                }

                
            }
       
        putchar('\n');
        fputc('\n', fichier);
        }
        fprintf(fichier,"Vous avez poser %d de X \nVous avez poser %d de O", count, count2);
        
    }
    fclose(fichier);
    

}

int** locatoin_grill(){
    int **grille = (int**) malloc(ligne*sizeof(int*));
    for(int a = 0; a < ligne; a++){
        grille[a] = (int*) malloc(col*sizeof(int));
    }
    
    return grille;
}



void piece_j1(int **grille){
    int y = 0;
    
    printf("choissez une colone entre joueur 1 (0, 6): ");
    scanf("%d", &y);

        for (int i = 6-1; i >= 0; i--)
        {
            if (grille[i][y] == 0 && grille[i][y] != 2)
            {
                grille[i][y] = 1;
                break;
               

            }
        
        
        }

    
  
}

void piece_j2(int **grille){
    int y = 0, count = 0;
    printf("choissez une colone entre joueur 2 (0, 6): ");
    scanf("%d", &y);

    for (int i = 6-1; i >= 0; i--)
    {
        if (grille[i][y] == 0 && grille[i][y] != 1)
        {
            grille[i][y] = 2;
            count++;
            break;

        }
        
    }
    
}

bool check_colone_j1(int** grille, bool victoire){
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0 ; j < col; j++)
        {
            if(grille[i][j] == 1 && grille[i+1][j] == 1 && grille[i+2][j] == 1 && grille[i+3][j] == 1){
                victoire = true;
                
            }
            
            
        }
        
    }
    return victoire;
}

bool check_colone_j2(int** grille, bool victoire_2){
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0 ; j < col; j++)
        {
            if(grille[i][j] == 2 && grille[i+1][j] == 2 && grille[i+2][j] == 2 && grille[i+3][j] == 2){
                victoire_2 = true;
            }
            
            
        }
        
    }
    return victoire_2;
}

bool check_ligne_j1(int** grille, bool victoire){
    
    for (int i = 0; i <ligne ; i++)
    {
        for (int j = 0 ; j < 3; j++)
        {
            if(grille[i][j] == 1 && grille[i][j+1] == 1 && grille[i][j+2] == 1 && grille[i][j+3] == 1){
                victoire = true;
                
            }
            
            
        }
        
    }
    return victoire;
}

bool check_ligne_j2(int** grille, bool victoire_2){
    
    for (int i = 0; i <ligne ; i++)
    {
        for (int j = 0 ; j < 3; j++)
        {
            if(grille[i][j] == 1 && grille[i][j+1] == 1 && grille[i][j+2] == 1 && grille[i][j+3] == 1){
                victoire_2 = true;
                
            }
            
            
        }
        
    }
    return victoire_2;
}

bool check_diag_j1(int** grille, bool victoire){
    
    for (int i = 0; i <= 2; i++)
    {
        for (int j = 0 ; j <= 3; j++)
        {
            int count = 0;
            for (int k = 0; k < 4; k++)
            {
                if (grille[i+k][j+k] == 1)
                {
                    count++;
                }
                else{
                    break;
                }
                if (count == 4)
                {
                    victoire = true;
                    
                }
                
                
            }
        
            
            
        }
        
    }

    for (int i = 0; i <= 2; i++)
    {
        for (int j = 4-1 ; j < col; j++)
        {
            int count = 0;
            for (int k = 0; k < 4; k++)
            {
                if (grille[i+k][j-k] == 1)
                {
                    count++;
                }
                else{
                    break;
                }
                if (count == 4)
                {
                    victoire = true;
                    
                }
                
                
            }
        
            
            
        }
        
    }
    return victoire;
}

bool check_diag_j2(int** grille, bool victoire_2){
    
    for (int i = 0; i <= 2; i++)
    {
        for (int j = 0 ; j <= 3; j++)
        {
            int count = 0;
            for (int k = 0; k < 4; k++)
            {
                if (grille[i+k][j+k] == 2)
                {
                    count++;
                }
                else{
                    break;
                }
                if (count == 4)
                {
                    victoire_2 = true;
                    
                }
                
                
            }
        
            
            
        }
        
    }

    for (int i = 0; i <= 2; i++)
    {
        for (int j = 4-1 ; j < col; j++)
        {
            int count = 0;
            for (int k = 0; k < 4; k++)
            {
                if (grille[i+k][j-k] == 2)
                {
                    count++;
                }
                else{
                    break;
                }
                if (count == 4)
                {
                    victoire_2 = true;
                    
                }
                
                
            }
        
            
            
        }
        
    }
    return victoire_2;
}




int main(int argc, char const *argv[])
{
    bool victoire = false, victoire_2 = false;
    int **grille = locatoin_grill(), tour = 0, saisie_joueur,y = 0;
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 7; j++) {
            grille[i][j] = 0;
        }
    }

    while (tour != 42)
    {
        grille_des(grille);

        piece_j1(grille);
        

        victoire = check_colone_j1(grille,victoire);
        victoire = check_ligne_j1(grille,victoire);
        victoire = check_diag_j1(grille,victoire);

        grille_des(grille);

        piece_j2(grille);

        victoire_2 = check_colone_j2(grille,victoire_2);
        victoire_2 = check_ligne_j2(grille,victoire_2);
        victoire_2 = check_diag_j2(grille,victoire_2);

        if (victoire == true)
        {
            printf("victoire du joueur 1");
            free(grille);
            break;
            
        }

        if (victoire_2 == true)
        {
            printf("victoire du joueur 2");
            free(grille);
            break;
            
        }

        if (tour == 42)
        {
            printf("parti nul");
            free(grille);
            break;
            
        }
        
        
        tour++;
               
    }
    
    return 0;
}
