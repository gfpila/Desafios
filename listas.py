"""
Nesse contexto, este Desafio propõe a implementação de uma relação que armazene a lista de chamada de uma determinada disciplina, contendo o nome do aluno, a nota e o status da sua matrícula (ativa ou cancelada).

São métodos que devem ser implementados neste Desafio:



Incluir e excluir alunos em qualquer ordem até o limite de 40;
Ordenar a lista por nota decrescente;
Apresentar a relação total de alunos e de alunos que estejam com a matricula ativa."""
import copy

class aluno:
    def __init__(self, nome, nota, status):
        self.nome = nome
        self.nota = nota
        self.status = status


listaAlunos = []
MAXALUNOS = 40
for i in range(MAXALUNOS):
    listaAlunos.append("VAZIO")

def inserirAluno():

    #VERIFICAR TAMANHO DA LISTA
    if listaAlunos[39] != "VAZIO":
        print("Lista Cheia!!")
        return False

    #RECUPERAR VALORES
    nome= input("Nome do aluno:  ")
    while True:
        nota = input("Nota do aluno:  ")
        try:
            nota = float(nota)
            break
        except:
            print("Digite um valor numérico")
            continue
    while True:
        status = input("Status da matrícula: (A: Ativa, N: Não Ativa)  ")
        if status == "A" or status == "N":
            break
        else:
            print("Digite A ou N")
    
    #INSERIR
    Aluno = aluno(nome, nota, status)
    listaAlunos.insert(0, Aluno)
    del listaAlunos[40]
    print("Aluno Adicionado!")
    
def excluirAluno(posicao):
    #GARANTIR POSIÇÃO CORRETA
    try:
        posicao = int(posicao)
        if not posicao > 0 and posicao <= 40:
            print("Digite uma posição de 1 a 40")
            return False
    except:
        print("Digite uma posição de 1 a 40")
        return False
    
    #VERIFICAR TAMANHO DA LISTA
    if listaAlunos[posicao - 1] == "VAZIO":
        print("Não há alunos nesta posição!")
    else:
        #EXCLUIR
        del listaAlunos[posicao-1]
        listaAlunos.append("VAZIO")
        print("Aluno removido!")

def ordenarNotas():
    global listaAlunos
    listaAlunosOrdenada = copy.deepcopy(listaAlunos)
    for item in reversed(listaAlunosOrdenada):
        if item == "VAZIO":
            listaAlunosOrdenada.remove(item)
    
    tamanhoLista = len(listaAlunosOrdenada)
    if tamanhoLista == 0:
        print("Lista Vazia!")
        return False
    
    notas = []
    listaOrdenada = []
    for k in range(tamanhoLista):
        notas.append((listaAlunosOrdenada[k].nota))

    notasOrdenadas = sorted(notas, reverse=True)

    for n in range(tamanhoLista):
        #NOTA DA PRIMEIRA POSICAO
        nota = notasOrdenadas[n]
        #ENCONTRAR POSICAO DESSA NOTA NO ARRAY ORIGINAL
        for i, notaAluno in enumerate(notas):
            if notaAluno == nota:
                posicaoAntiga = i
                break         
        #ME DE O ALUNO DA POSICAO ANTIGA
        aluno = listaAlunosOrdenada[posicaoAntiga]
        #COLOQUE ESTE ALUNO NA POSICAO REAL
        listaOrdenada.append(aluno)
    
    listaAlunos = listaOrdenada
    qtdVazio = 40 - len(listaAlunos)
    for i in range(qtdVazio):
        listaAlunos.append("VAZIO")
    print("Lista Ordenada!")
    

def informacoes():
    qtdAtiva = 0
    listaInformacoes = copy.deepcopy(listaAlunos)
    for item in reversed(listaInformacoes):
        if item == "VAZIO":
            listaInformacoes.remove(item)
    for i in range(len(listaInformacoes)):
        if listaInformacoes[i].status == "A":
            qtdAtiva += 1
        else:
            continue
    for i in range(len(listaInformacoes)):
        print(f"{i+1}:Nome: {listaInformacoes[i].nome}      Nota: {listaInformacoes[i].nota}     Status: {listaInformacoes[i].status}")
    print(f"Quantidade de alunos na lista: {len(listaInformacoes)}\nQuantidade de alunos com matricula ativa: {qtdAtiva}")


while True:
    opcao = input("O que deseja fazer?\n0: Ver lista.\n1: Adicionar aluno.\n2: Remover Auno.\n3: Ordenar Lista por notas.\n4: Sair\n")
    try:
        opcao = int(opcao)
        if opcao < 0 or opcao > 4:
            print("Digite um número de 0 a 4")
    except:
        print("Digite um número de 0 a 4")
    
    if opcao == 1:
        inserirAluno()
    elif opcao == 2:
        posicao = input("Em que posição da lista está o aluno que deseja excluir?  ")
        excluirAluno(posicao)
    elif opcao == 3:
        ordenarNotas()
    elif opcao == 4:
        break
    elif opcao == 0:
        informacoes()