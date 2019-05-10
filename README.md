# Grammar-Checker

Nume student: Alexandru Glodeanu 

Nume coordonator: Alexandru Cosmin

Nume proiect: Verificare generare cuvant pentru o gramatica regulata

Input: O gramatica regulata oarecare si o lista de cuvinte

Output:  Pentru  fiecare cuvant  dat  ca  input  se  precizeaza  daca  acesta  apartine limabajului generat de gramatica.

Exemplu:

G: N= {S, A}

Σ = {a, b, c}

S → aS

S → bA

A → ε

A → cA

w = ab ∈L(G)

w = aaaaaaabcccccccc ∈L(G)

w = b ∈L(G)

w = bcc ∈L(G)

w = ac ∉L(G)

w = abbc ∉L(G)
