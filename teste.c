#include <stdio.h>

// Constantes para o tamanho do tabuleiro e dos navios
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

// --- Protótipos de Funções ---

// Função para inicializar o tabuleiro com AGUA (0)
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]);

// Função para tentar posicionar um navio.
// Retorna 1 (VERDADEIRO) se o posicionamento foi bem-sucedido e 0 (FALSO) caso contrário.
int posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO],
                    int linhaInicial, int colunaInicial,
                    int dLinha, int dColuna); // dLinha e dColuna são os incrementos

// Função para exibir o tabuleiro com cabeçalhos de linha e coluna
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]);

int main()
{
  // 1. Criar um Tabuleiro 10x10 e inicializá-lo com 0 (ÁGUA)
  int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
  inicializarTabuleiro(tabuleiro);

  printf("--- Desafio Batalha Naval - Nível Intermediário ---\n");
  printf("Posicionando 4 navios de tamanho %d (representados por %d)...\n\n", TAMANHO_NAVIO, NAVIO);

  // Variável para rastrear o sucesso de cada posicionamento (0 = FALSO, 1 = VERDADEIRO)
  int sucesso;

  // --- Posicionamento dos Quatro Navios (Tamanho fixo = 3) ---

  // Navio 1: Vertical (Linha aumenta, Coluna não muda) -> dLinha=1, dColuna=0
  // Coordenada Inicial: H2 (Índices [1][7]) -> Ocupa H2, H3, H4
  sucesso = posicionarNavio(tabuleiro, 1, 7, 1, 0);
  printf("Posicionamento Navio 1 (Vertical - H2): %s\n", sucesso ? "SUCESSO" : "FALHA");

  // Navio 2: Horizontal (Coluna aumenta, Linha não muda) -> dLinha=0, dColuna=1
  // Coordenada Inicial: D6 (Índices [5][3]) -> Ocupa D6, E6, F6
  sucesso = posicionarNavio(tabuleiro, 5, 3, 0, 1);
  printf("Posicionamento Navio 2 (Horizontal - D6): %s\n", sucesso ? "SUCESSO" : "FALHA");

  // Navio 3: Diagonal Principal (Linha e Coluna aumentam) -> dLinha=1, dColuna=1
  // Coordenada Inicial: A1 (Índices [0][0]) -> Ocupa A1, B2, C3
  sucesso = posicionarNavio(tabuleiro, 0, 0, 1, 1);
  printf("Posicionamento Navio 3 (Diagonal ↘ - A1): %s\n", sucesso ? "SUCESSO" : "FALHA");

  // Navio 4: Diagonal Secundária (Linha aumenta, Coluna diminui) -> dLinha=1, dColuna=-1
  // Coordenada Inicial: I3 (Índices [2][8]) -> Ocupa I3, H4, G5
  sucesso = posicionarNavio(tabuleiro, 2, 8, 1, -1);
  printf("Posicionamento Navio 4 (Diagonal ↙ - I3): %s\n", sucesso ? "SUCESSO" : "FALHA");

  printf("\n");

  // 2. Exibir o Tabuleiro
  exibirTabuleiro(tabuleiro);

  return 0;
}

// --- Definições de Funções (Inalteradas) ---

void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO])
{
  for (int i = 0; i < TAMANHO_TABULEIRO; i++)
  {
    for (int j = 0; j < TAMANHO_TABULEIRO; j++)
    {
      tabuleiro[i][j] = AGUA;
    }
  }
}

int posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO],
                    int linhaInicial, int colunaInicial,
                    int dLinha, int dColuna)
{

  int linhaAtual, colunaAtual;

  // 1. Validação: Checar se o navio cabe e se não há sobreposição
  for (int k = 0; k < TAMANHO_NAVIO; k++)
  {
    linhaAtual = linhaInicial + k * dLinha;
    colunaAtual = colunaInicial + k * dColuna;

    // Validação 1: Limites do Tabuleiro
    if (linhaAtual < 0 || linhaAtual >= TAMANHO_TABULEIRO ||
        colunaAtual < 0 || colunaAtual >= TAMANHO_TABULEIRO)
    {
      return 0; // FALHA (Fora dos limites)
    }

    // Validação 2: Sobreposição
    if (tabuleiro[linhaAtual][colunaAtual] == NAVIO)
    {
      return 0; // FALHA (Sobreposição)
    }
  }

  // 2. Posicionamento: Se todas as validações passaram, marque as posições
  for (int k = 0; k < TAMANHO_NAVIO; k++)
  {
    linhaAtual = linhaInicial + k * dLinha;
    colunaAtual = colunaInicial + k * dColuna;
    tabuleiro[linhaAtual][colunaAtual] = NAVIO; // Marca com 3
  }

  return 1; // SUCESSO
}

void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO])
{
  char letras[TAMANHO_TABULEIRO] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

  // 1. Imprimir o cabeçalho das Colunas (A B C ...)
  printf("    ");
  for (int j = 0; j < TAMANHO_TABULEIRO; j++)
  {
    printf(" %c ", letras[j]);
  }
  printf("\n");

  // 2. Imprimir Linhas e Conteúdo da Matriz
  for (int i = 0; i < TAMANHO_TABULEIRO; i++)
  {
    // Imprimir o número da Linha (1 a 10)
    printf("%2d |", i + 1);

    for (int j = 0; j < TAMANHO_TABULEIRO; j++)
    {
      printf(" %d ", tabuleiro[i][j]);
    }
    printf("\n");
  }
}