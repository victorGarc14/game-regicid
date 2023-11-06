#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

struct tabuleiro{
    int intriga;
    int verificar;
    char nome;
};

int dificuldade(){
int escolha;
    printf("Escolha a dificuldade da partida:\n");
    printf("1 - Facil\n");
    printf("2 - Medio\n");
    printf("3 - Dificil\n");
    printf("Ou pressione 4 para sair.\n");
    scanf("%d", &escolha);
    return escolha;
}
void *preencher(char valores[],int valorKza[]){
valores[0]='A';
valores[1]='B';
valores[2]='C';
valores[3]='D';
valores[4]='E';
valores[5]='F';
valorKza[0]=0;
valorKza[1]=1;
valorKza[2]=2;
valorKza[3]=3;
valorKza[4]=4;
valorKza[5]=6;
}
void embaralharValor(char valores[],int tamanho,int valorKza[]){
for (int i = tamanho - 1; i > 0; i--) {
    int j = rand() % (i + 1);
    char temp = valores[i];
         valores[i] = valores[j];
         valores[j] = temp;

    int tmp = valorKza[i];
         valorKza[i]=valorKza[j];
         valorKza[j]=tmp;
}

}
void limpar(){
system("clear");
system("cls");
}

void embaralhar (char v[36]){
    int vteste[6] ,v1[36], i , x;

    for (i=0; i<6; i++){
        vteste[i]= 0;
    }

    srand(time(NULL));
    for (i=0 ; i<36 ; i++){
        do{
            x = (rand()%6);
        }
        while (vteste[x] >= 6);

        v1[i] = x;
        vteste[x]++;
    }
    for(i=0;i<36;i++){
        if(v1[i]==0){
                v[i]='A';
            }
        else if(v1[i]==1){
                v[i]='B';
            }

        else if(v1[i]==2){
                v[i]='C';
            }
        else if(v1[i]==3){
                v[i]='D';
            }
        else if(v1[i]==4){
                v[i]='E';
            }
        else if(v1[i]==5){
                v[i]='F';
            }
    }
}

void preparaJogo (struct tabuleiro m[11][11]){
    int i , j;
    for(i=0 ; i<11 ; i++){
        for(j=0 ; j<11 ; j++){
            m[i][j].intriga = 0;
            m[i][j].nome = '-';
            m[i][j].verificar = 0;
        }
    }
}

void fasedeExpansao (struct tabuleiro m[11][11], char v[36]){
    int i , j , z = 1 , cont=0 , a1 , b1 , c1 , a2 , b2 , c2 , a3 , b3 , c3 , a4 , b4 , c4 , x , y , k , l;
    int menorl=5 , maiorl=5 , menorc=5 , maiorc=5 , valor;
    m[5][5].nome = v[0];
    m[5][5].verificar = 1;
    for(i=0 ; i<11 ; i++){
            for(j=0 ; j<11 ; j++){
                printf(" %c ",m[i][j].nome);
            }
            printf("\n");
    }
    do {
        printf("A peca do comeco da pilha eh %c!! \n",v[z]);
        printf("Porfavor digite a linha selecionada para colocar sua peca:");
        scanf("%d",&i);
        printf("Porfavor digite a coluna selecionada para colocar sua peca:");
        scanf("%d",&j);
        for(k=0 ; k<11 ; k++){
            for(l=0 ; l<11 ; l++){
              if(m[k][l].verificar != 0){
                if(k < menorl){
                    menorl = k;
                    }
                if(k > maiorl){
                    maiorl = k;
                    }
                }
            }
        }
        for(k=0 ; k<11 ; k++){
            for(l=0 ; l<11 ; l++){
              if(m[k][l].verificar != 0){
                if(l < menorc){
                    menorc = l;
                    }
                if(l > maiorc){
                    maiorc = l;
                    }
                }
            }
        }
        limpar();
        y = (maiorc - menorc);
        x = (maiorl - menorl);
        if(m[i][j].verificar != 0 ){
            printf("Coordenada Invalida!! \n");
            printf("Digite Novamente!! \n");
        }
        else{
            if(x<5 && y<5){
                valor = 1;
            }
            else if(x==5 && y==5){
                valor = 2;
            }
            else if(x==5 && y<5){
                valor = 3;
            }
            else if(x<5 && y==5){
                valor = 4;
            }
        limpar();
        switch( valor ){
            case 1:
                a1 = validarLimite1(m,i,j);
                b1 = validarLinha1(m,i,j);
                c1 = validarColuna1(m,i,j);
                if(a1 == 1 && (b1 == 1 || c1 == 1)){
                    m[i][j].nome = v[z];
                    m[i][j].verificar = 1;
                    cont++;
                    z++;
                }
            break;
            case 2:
                a2 = validarLimite2(m,i,j,menorl,maiorl,menorc,maiorc);
                b2 = validarLinha2(m,i,j,menorl,maiorl,menorc,maiorc);
                c2 = validarColuna2(m,i,j,menorl,maiorl,menorc,maiorc);
                if(a2 == 1 && (b2 == 1 || c2 == 1)){
                    m[i][j].nome = v[z];
                    m[i][j].verificar = 1;
                    cont++;
                    z++;
                }
            break;
            case 3:
                a3 = validarLimite3(m,i,j,menorl,maiorl);
                b3 = validarLinha3(m,i,j,menorl,maiorl,menorc,maiorc);
                c3 = validarColuna3(m,i,j,menorl,maiorl,menorc,maiorc);
                if(a3 == 1 && (b3 == 1 || c3 == 1)){
                    m[i][j].nome = v[z];
                    m[i][j].verificar = 1;
                    cont++;
                    z++;
                }
            break;
            case 4:
                a4 = validarLimite4(m,i,j,menorc,maiorc);
                b4 = validarLinha4(m,i,j,menorl,maiorl,menorc,maiorc);
                c4 = validarColuna4(m,i,j,menorl,maiorl,menorc,maiorc);
                if(a4 == 1 && (b4 == 1 || c4 == 1)){
                    m[i][j].nome = v[z];
                    m[i][j].verificar = 1;
                    cont++;
                    z++;
                }
            break;
        }
        }

        for(i=0 ; i<11 ; i++){
            for(j=0 ; j<11 ; j++){
                printf(" %c ",m[i][j].nome);
            }
            printf ("\n");
        }
    }
    while(cont !=35);

}
int validarLimite1(struct tabuleiro m[11][11], int i , int j){
    if(i<0 || i>10 || j<0 || j>10){
        return 0;
    }
    else{
        return 1;
    }
}

int validarLimite2 (struct tabuleiro m[11][11], int i , int j , int menorl , int maiorl , int menorc , int maiorc){
    if(i<menorl || i>maiorl || j<menorc || j>maiorc){
        return 0;
    }
    else{
        return 1;
    }
}
int validarLimite3 (struct tabuleiro m[11][11], int i , int j ,int menorl ,int maiorl){
    if(i<menorl || i>maiorl || j<0 || j>10){
        return 0;
    }
    else{
        return 1;
    }
}
int validarLimite4 (struct tabuleiro m[11][11], int i , int j , int menorc , int maiorc){
    if(i<0 || i>10 || j<menorc || j>maiorc){
        return 0;
    }
    else{
        return 1;
    }
}

int validarLinha1(struct tabuleiro m[11][11], int i , int j){
    if((i-1) < 0 && (j-1) < 0 && (m[i][j+1].verificar != 0 || m[i+1][j].verificar != 0)){
        return 1;
    }
    else if ((i+1) > 10 && (j-1) < 0 && (m[i][j+1].verificar == 0 || m[i-1][j].verificar == 0)){
        return 0;
    }
    else if((i-1) >= 0 && (j-1) < 0 && (m[i][j+1].verificar != 0 || m[i+1][j].verificar != 0 || m[i-1][j].verificar != 0 )){
        return 1;
    }
    else if((i-1) < 0 && (j-1) >= 0 && (m[i][j+1].verificar != 0 || m[i][j-1].verificar != 0 || m[i+1][j].verificar != 0)){
        return 1;
    }
    else if((i+1) > 10 && (j+1) > 10 && (m[i][j-1].verificar != 0 || m[i-1][j].verificar != 0 )){
        return 1;
    }
    else if(i != 0 && i != 10 && j != 0 && j != 10 && (m[i][j+1].verificar != 0 || m[i][j-1].verificar != 0 ||m[i+1][j].verificar != 0 || m[i-1][j].verificar != 0)){
        return 1;
    }
    else{
        return 0;
    }
}

int validarLinha2(struct tabuleiro m[11][11], int i , int j , int menorl , int maiorl , int menorc , int maiorc){
    if((i-1) < menorl && (j-1) < menorc && (m[i][j+1].verificar != 0 || m[i+1][j].verificar != 0)){
        return 1;
    }
    else if((i-1) >= menorl && (j-1) < menorc && (m[i][j+1].verificar != 0 || m[i+1][j].verificar != 0 || m[i-1][j].verificar != 0 )){
        return 1;
    }
    else if((i-1) < menorl && (j-1) >= menorc && (m[i][j+1].verificar != 0 || m[i][j-1].verificar != 0 || m[i+1][j].verificar != 0)){
        return 1;
    }
    else if((i+1) > maiorl && (j+1) > maiorc && (m[i][j-1].verificar != 0 || m[i-1][j].verificar != 0 )){
        return 1;
    }
    else if(i != menorl && i != maiorl && j != menorc && j != maiorc && (m[i][j+1].verificar != 0 || m[i][j-1].verificar != 0 ||m[i+1][j].verificar != 0 || m[i-1][j].verificar != 0)){
        return 1;
    }
    else{
        return 0;
    }
}

int validarLinha3(struct tabuleiro m[11][11], int i , int j , int menorl , int maiorl , int menorc , int maiorc){
    if((i-1) < menorl && (j-1) < 0 && (m[i][j+1].verificar != 0 || m[i+1][j].verificar != 0)){
        return 1;
    }
    else if((i-1) >= menorl && (j-1) < 0  && (m[i][j+1].verificar != 0 || m[i+1][j].verificar != 0 || m[i-1][j].verificar != 0 )){
        return 1;
    }
    else if((i-1) < menorl && (j-1) >= 0 && (m[i][j+1].verificar != 0 || m[i][j-1].verificar != 0 || m[i+1][j].verificar != 0)){
        return 1;
    }
    else if((i+1) > maiorl && (j+1) > 10 && (m[i][j-1].verificar != 0 || m[i-1][j].verificar != 0 )){
        return 1;
    }
    else if(i != menorl && i != maiorl && j != 0 && j != 10 && (m[i][j+1].verificar != 0 || m[i][j-1].verificar != 0 ||m[i+1][j].verificar != 0 || m[i-1][j].verificar != 0)){
        return 1;
    }
    else{
        return 0;
    }
}

int validarLinha4(struct tabuleiro m[11][11], int i , int j , int menorl , int maiorl , int menorc , int maiorc){
    if((i-1) < 0 && (j-1) < menorc && (m[i][j+1].verificar != 0 || m[i+1][j].verificar != 0)){
        return 1;
    }
    else if((i-1) >= 0 && (j-1) < menorc && (m[i][j+1].verificar != 0 || m[i+1][j].verificar != 0 || m[i-1][j].verificar != 0 )){
        return 1;
    }
    else if((i-1) < 0 && (j-1) >= menorc && (m[i][j+1].verificar != 0 || m[i][j-1].verificar != 0 || m[i+1][j].verificar != 0)){
        return 1;
    }
    else if((i+1) > 10 && (j+1) > maiorc && (m[i][j-1].verificar != 0 || m[i-1][j].verificar != 0 )){
        return 1;
    }
    else if(i != 0 && i != 10 && j != menorc && j != maiorc && (m[i][j+1].verificar != 0 || m[i][j-1].verificar != 0 ||m[i+1][j].verificar != 0 || m[i-1][j].verificar != 0)){
        return 1;
    }
    else{
        return 0;
    }
}

int validarColuna1(struct tabuleiro m[11][11], int i , int j){
    if((i+1) > 10 && (j+1) > 10 && (m[i][j-1].verificar != 0 || m[i-1][j].verificar != 0 )){
        return 1;
    }
    else if ((i-1) < 0 && (j+1) > 10 && (m[i][j-1].verificar == 0 || m[i+1][j].verificar == 0)){
        return 0;
    }
    else if((i+1) <= 10 && (j+1) > 10 && (m[i][j-1].verificar != 0 || m[i+1][j].verificar != 0 || m[i-1][j].verificar != 0 )){
        return 1;
    }
    else if((i+1) > 10 && (j+1) <= 10 && (m[i][j+1].verificar != 0 || m[i][j-1].verificar != 0 || m[i-1][j].verificar != 0 )){
        return 1;
    }
    else if((i-1) < 0 && (j-1) < 0 && (m[i][j+1].verificar != 0 || m[i+1][j].verificar != 0)){
        return 1;
    }
    else if(i != 0 && i != 10 && j != 0 && j != 10 && (m[i][j+1].verificar != 0 || m[i][j-1].verificar != 0 ||m[i+1][j].verificar != 0 || m[i-1][j].verificar != 0)){
        return 1;
    }
    else{
        return 0;
    }
}

int validarColuna2(struct tabuleiro m[11][11], int i , int j , int menorl , int maiorl , int menorc , int maiorc){
    if((i+1) > maiorl && (j+1) > maiorc && (m[i][j-1].verificar != 0 || m[i-1][j].verificar != 0 )){
        return 1;
    }
    else if((i+1) <= maiorl && (j+1) > maiorc && (m[i][j-1].verificar != 0 || m[i+1][j].verificar != 0 || m[i-1][j].verificar != 0 )){
        return 1;
    }
    else if((i+1) > maiorl && (j+1) <= maiorc && (m[i][j+1].verificar != 0 || m[i][j-1].verificar != 0 || m[i-1][j].verificar != 0 )){
        return 1;
    }
    else if((i-1) < menorl && (j-1) < menorc && (m[i][j+1].verificar != 0 || m[i+1][j].verificar != 0)){
        return 1;
    }
    else if(i != menorl && i != maiorl && j != menorc && j != maiorc && (m[i][j+1].verificar != 0 || m[i][j-1].verificar != 0 ||m[i+1][j].verificar != 0 || m[i-1][j].verificar != 0)){
        return 1;
    }
    else{
        return 0;
    }
}

int validarColuna3(struct tabuleiro m[11][11], int i , int j , int menorl , int maiorl , int menorc , int maiorc){
    if((i+1) > maiorl && (j+1) > 10 && (m[i][j-1].verificar != 0 || m[i-1][j].verificar != 0 )){
        return 1;
    }
    else if((i+1) <= maiorl && (j+1) > 10 && (m[i][j-1].verificar != 0 || m[i+1][j].verificar != 0 || m[i-1][j].verificar != 0 )){
        return 1;
    }
    else if((i+1) > maiorl && (j+1) <= 10 && (m[i][j+1].verificar != 0 || m[i][j-1].verificar != 0 || m[i-1][j].verificar != 0 )){
        return 1;
    }
    else if((i-1) < menorl && (j-1) < 0 && (m[i][j+1].verificar != 0 || m[i+1][j].verificar != 0)){
        return 1;
    }
    else if(i != menorl && i != maiorl && j != 0 && j != 10 && (m[i][j+1].verificar != 0 || m[i][j-1].verificar != 0 ||m[i+1][j].verificar != 0 || m[i-1][j].verificar != 0)){
        return 1;
    }
    else{
        return 0;
    }
}

int validarColuna4(struct tabuleiro m[11][11], int i , int j , int menorl , int maiorl , int menorc , int maiorc){
    if((i+1) > 10 && (j+1) > maiorc && (m[i][j-1].verificar != 0 || m[i-1][j].verificar != 0 )){
        return 1;
    }
    else if((i+1) <= 10 && (j+1) > maiorc && (m[i][j-1].verificar != 0 || m[i+1][j].verificar != 0 || m[i-1][j].verificar != 0 )){
        return 1;
    }
    else if((i+1) > 10 && (j+1) <= maiorc && (m[i][j+1].verificar != 0 || m[i][j-1].verificar != 0 || m[i-1][j].verificar != 0 )){
        return 1;
    }
    else if((i-1) < 0 && (j-1) < menorc && (m[i][j+1].verificar != 0 || m[i+1][j].verificar != 0)){
        return 1;
    }
    else if(i != 0 && i != 10 && j != menorc && j != maiorc && (m[i][j+1].verificar != 0 || m[i][j-1].verificar != 0 ||m[i+1][j].verificar != 0 || m[i-1][j].verificar != 0)){
        return 1;
    }
    else{
        return 0;
    }
}

int adjacentes(int i1, int j1, int i2, int j2) {

  if (i1 == i2) {

    if (abs(j1 - j2) == 1) {
      return 1;
    }

  } else if (j1 == j2) {

    if (abs(i1 - i2) == 1) {
      return 1;
    }

  }

  return 0;

}


void intriga(struct tabuleiro m[11][11], int v[36], int valorKza[],char valores[]){
    int *valorI=(int*)malloc(6*sizeof(int));
    int i, j, l, c, opcao = 0, escolha, clBloqueados = 0,clasb = 0, pebij = 0, peblc = 0;
    int pb[6];
    char cla[6] = {0};
    int bloqueadoil[6], bloqueadojc[6];
    char valor, bloqueado, n;

    for(int i=0;i<5;i++){
                printf("A casa com valor %d e: %c \n",i, valores[i]);
        }
    printf("A casa com valor 6 e: %c\n", valores[5]);
    for(int i=0;i<6;i++){
        if(valores[i]=='A') valorI[0]=i;
        else if(valores[i]=='B') valorI[1]=i;
        else if(valores[i]=='C') valorI[2]=i;
        else if(valores[i]=='D') valorI[3]=i;
        else if(valores[i]=='E') valorI[4]=i;
        else if(valores[i]=='F') valorI[5]=i;
    }
    for(int i=0;i<6;i++){
            if(valorI[i]==5) valorI[i]+=1;
     }
    for (int h = 0; h < 6; h++) {

        do {
            printf("Escolha a linha da peça 1: ");
            scanf("%d", &i);
            printf("Escolha a coluna da peça 1: ");
            scanf("%d", &j);
            printf("Escolha a linha da peça 2: ");
            scanf("%d", &l);
            printf("Escolha a coluna da peça 2: ");
            scanf("%d", &c);

             if (m[i][j].nome == '-' || m[l][c].nome == '-') {
             printf("Peça inválida! \n");
             } else if (!adjacentes(i, j, l, c)) {
             printf("Peça não adjacente! \n");
             }

            for (int f = 0; f < h; f++){
            if (i == bloqueadoil[f] && j == bloqueadojc[f]) {
                printf("A peça escolhida 1 está bloqueada! \n");
                pebij = 1;
                break;
            }
            else pebij = 0;
            }

            for (int f = 0; f < h; f++){
            if (l == bloqueadoil[f] && c == bloqueadojc[f]) {
                printf("A peça escolhida 2 está bloqueada! \n");
                peblc = 1;
                break;
            }
            else peblc = 0;
            }
            int cij = 0;
            int clc = 0;

            for (int d = 0; d < h; d++){

            if (m[i][j].nome == cla[d]){
                cij = 1;
            }
            if (m[l][c].nome == cla[d]){
                clc = 1;
            }
            if (cij == 1 && clc == 1){
                printf("Os clãs de ambas as peças estão bloqueados! \n");
                clasb = 1;
                break;
            }
            else clasb = 0;
            }

        } while (m[i][j].nome == '-' || m[l][c].nome == '-' || !adjacentes(i, j, l, c) || pebij == 1 || clasb == 1 || peblc == 1);


        valor = m[i][j].nome;

        m[i][j].nome = m[l][c].nome;

        m[l][c].nome = valor;

        exibeTabuleiro(m, v);

         while (opcao != 1 && opcao != 2) {
            printf("Escolha a peça a ser bloqueada: ");
            scanf("%d", &opcao);
        }

        if (opcao == 1) {
            bloqueadoil[h] = l;
            bloqueadojc[h] = c;
            bloqueado = m[l][c].nome;
        } else if (opcao == 2) {
            bloqueadoil[h] = i;
            bloqueadojc[h] = j;
            bloqueado = m[i][j].nome;
        }
        opcao = 0;

        clBloqueados++;

        printf("A peça %c foi bloqueada! \n", bloqueado);

        int cnb = 0;

        while ((m[i][j].nome != n && m[l][c].nome != n) || cnb == 1){

        getchar();

        printf("Escolha um dos clãs para ser bloqueado: ");
        scanf("%c",&n);
        for (int e = 0; e < 6; e++){
            if (cla[e] == n){
                printf("clã já bloqueado, escolha outro! \n");
                cnb = 1;
            }
            else{ cnb = 0;
            }

            if (cnb == 1){
                break;
            }
        }
        };

        cla[h] = n;
        n = 0;

    }
    int cont1 = 0;
    int cont2 = 0;
    int cont3 = 0;
    int cont4 = 0;
    int cont5 = 0;
    int cont6 = 0;
    if (clBloqueados == 6) {
            for (int g = 1; g < 5; g++){
                for (int k = 1; k < 5; k++){
                    if(m[g][k].nome == 'A'){
                        cont1++;
                    }
                    else if(m[g][k].nome == 'B'){
                        cont2++;
                    }
                    else if(m[g][k].nome == 'C'){
                        cont3++;
                    }
                    else if(m[g][k].nome == 'D'){
                        cont4++;
                    }
                    else if(m[g][k].nome == 'E'){
                        cont5++;
                    }
                    else if(m[g][k].nome == 'F'){
                        cont6++;
                    }
            }
    }
    printf("O clã A tem %d peças\n",cont1);
    printf("O clã B tem %d peças\n",cont2);
    printf("O clã C tem %d peças\n",cont3);
    printf("O clã D tem %d peças\n",cont4);
    printf("O clã E tem %d peças\n",cont5);
    printf("O clã F tem %d peças\n",cont6);
    }
    if(valorI[0]==cont1 && valorI[1]==cont2 && valorI[2]==cont3 && valorI[3]==cont4 && valorI[4]==cont5 && valorI[5]==cont6)
        printf("Voce venceu!!!");
    else printf("Você perdeu!!!");

    printf("\n O jogo terminou!");
}


void exibeTabuleiro(struct tabuleiro m[11][11], int v[36]){
    int i, j;
    limpar();
    printf("\n");

    for (i = 0; i < 11; i++) {
        printf("%d ", i);
        for (j = 0; j < 11; j++) {
            if (m[i][j].nome != '-') {
                if (i!=10) printf(" (%c) ", m[i][j].nome);
                else printf("(%c) ", m[i][j].nome);
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
    printf("\n");

}
