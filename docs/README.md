# uni_agenda
A CLI interface for managing tasks, exams and deadlines in university
```
AVISO: Este branch é experimental e não tem todos os testes desenvolvidos!
Observe os ISSUES para mais informações.
```

### Class hierarchy (temp)
- **Curso**
  - Nome
  - **Semestre** (V)
    - Ano
    - Semestre
    - Data inicial
    - Data final
    - **Cadeira** (V)
      - Nome
      - Sigla
      - Código
      - Créditos
      - **Tempo**
        - (data inínio)
        - (data fim)
        - Tempo gasto
      - **Avaliação** (V)
        - Nome
        - Peso
        - Data
        - Cotação
      - **Tarefa** (V)
        - Lista exercícios (str)
        - Data inicial
        - Data final
        - Check
      - **Sumários** (V)
        - Lista de matérias (str)
        - Data
        - Check
