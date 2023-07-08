# uni_agenda
A CLI interface for managing tasks, exams and deadlines in university

### Class hierarchy (temp)
- **Curso**
  - Nome
  - **Semestre** (V)
    - Ano
    - Semestre
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