#### Table of contents:
- [scope & visibilità](#scope-e-visibilità)
  - [parametri attuali e formali](#parametri)
- [stack](#stack)
- [funzioni ricorsive](#funzioni-ricorsive)
  - [definizione](#definizione)
  - [Ricorsione diretta](#ricorsione-diretta)
  - [Ricorsione indiretta](#ricorsione-indiretta)
- [Alcune applicazioni](#alcune-applicazioni)
  - [Divide & Conquer](#divide--conquer)
  - [Programmazione Dinamica](#programmazione-dinamica)
- [ricorsione vs iterazione](#ricorsione-vs-iterazione)
- [tail call optimization](#tail-call)
- [esercizi](#esercizi)

---

## Scope e visibilità

[link1]:https://www.w3schools.in/c-tutorial/variable-scope/

>A scope is a region of the program, and the scope of variables refers to the area of the program where the variables can be accessed after its declaration. [source](link1)

In C ogni variabile è definita in uno scope, all'interno della quale esiste ed è accessibile. La stessa variabile non potrà essere usata o letta al di fuori del suo scope.

Le variabili possono essere definite in 3 posti:
+ localmente
+ globalmente
+ come parametri

#### Variabili locali

Tutte le variabili definite all'interno di un blocco {} (che sarà il loro scope). Possono essere usate solo al suo interno.`

#### Variabili globali

Variabili accessibili da tutto il programma in ogni momento, definite fuori da ogni blocco.
A differenza delle locali, le globali vengono inizializzate automaticamente a 0 dal compilatore. 

#### Parametri
Sono variabili dichiarate insieme al prototipo della funzione, e hanno come scope tutta la funzione, trattate come fossero variabili locali.
Vengono inizializzate al momento della chiamata.

Questo viene detto **parametro formale**. 
`int func(int a, int b)`, _a_ e _b_ sono parametri formali

Invece le variabili i cui valori vengono passati alla funzione sono detti **parametri attuali** e nel momento della chiamata vanno ad inizializzare i parametri formali.
Non hanno un proprio scopo specifico.

`func(5, 10)`, _5_ e _10_ sono parametri attuali, dopo questa chiamata, il programma inizia a svolgere 'func', con _a = 5_ e _b = 10_.

Nel caso in cui i parametri attuali siano definiti nello stesso scope della funzione, dalla funzione potrò accedere dalla funzione ai parametri attuali.

---

## Stack

Lo stack è l'area di memoria che si occupa di gestire il passaggio di parametri e di risultati tra funzioni. Uno stack per ogni thread, alla fine viene rimosso.
Il funzionamento è analogo a quello di una pila.

**FI-LO**: First In, Last Out

Ad ogni invocazione di una funzione, le viene riservato un nuovo stack frame, nel quale verranno allocate tutte le variabili locali alla funzione. Il frame corrisponde quindi allo scope per le variabili locali.
Questo frame sarà sopra la funzione chiamante e sotto la funzione chiamata.
Non appena la funzione finisce l'esecuzione, il valore restituito viene passato nel frame della funzione chiamante, mentre il suo frame viene eliminato.

La dimensione di ogni frame va da minimo 4 byte a centinaia di kilobyte. Ad ogni chiamata di funzione questo spazio verrà occupato, ed avendo lo stack una dimensione fissa può accadere che finisca la memoria (`Stack overflow`)
**Ogni chiamata di funzione ha** quindi anche un **costo di memoria** e cicli di clock ( **tempo** ).

[approfondimenti](http://www.dis.uniroma1.it/~liberato/struct/ricorsione/recatt.shtml)

---

## Funzioni ricorsive:
### Definizione:

>Una funzione è detta ricorsiva se chiama se stessa, direttamente o indirettamente.

oppure

>Un algoritmo ricorsivo è un algoritmo espresso in termini di se stesso

### Ricorsione diretta

L'algoritmo richiama se stesso fino al verificarsi di una condizione chiamata condizione di terminazione, che in genere si ha con particolari valori di input.

_Esempio:_ [(fat.c)](examples/fat.c "fat.c")
```c
int fat(int n){
	if (n == 0) //condizione di terminazione
		return 1;
	else
		return n*fat(n-1); //chiamata ricorsiva
}
```

### Ricorsione indiretta

Se la funzione chiama se stessa indirettamente, quindi da un'altra funzione, lei stessa deve chiamare la seconda funzione. In questo caso si dicono funzioni mutuamente ricorsive.

_Esempio:_ [(odd_or_even.c)](examples/odd_or_even.c "odd_or_even.c")
```c
bool even( int n ){
	if( n == 0 )
		return true;
	else
		return odd(abs(n)-1);
}
bool odd( int n ){
	if( n == 0 )
		return false;
	else
		return even(abs(n)-1);
}
```

---

## Alcune applicazioni:

[link]:https://medium.com/@maheshkariya/difference-between-divide-and-conquer-algo-and-dynamic-programming-4a657bcb6187 "Medium"

- #### Divide & Conquer:

Detto anche 'divide et impera'

>Divide and Conquer works by dividing the problem into sub-problems, conquer each sub-problem recursively and combine these solutions. ([source][link])

L'esecuzione dell'algoritmo su un insieme di dati comporta la semplificazione o suddivisione dell'insieme di dati e l'applicazione dello stesso algoritmo agli insiemi di dati semplificati.(è il caso dell'_esempio 1_, del _binary search_ e _Quicksort_)

È il metodo più elegante, ma spesso porta a ripetere calcoli già svolti.

- #### Programmazione Dinamica

>Dynamic Programming is a technique for solving problems with overlapping subproblems. Each sub-problem is solved only once and the result of each sub-problem is stored in a table ( generally implemented as an array or a hash table) for future references. These sub-solutions may be used to obtain the original solution and the technique of storing the sub-problem solutions is known as memoization. ([source][link])

![Dynamic programming in a nutshell](https://media.geeksforgeeks.org/wp-content/uploads/01-DP-vs-DC-DP-vs-DC-diagram-1024x492.png) [source](https://www.geeksforgeeks.org/dynamic-programming-vs-divide-and-conquer/ "G4G, Dynamic programming vs Divide and conquer")

---

## Ricorsione vs Iterazione

*"asking recursion or iteration is like asking for elegance or performance."* [**SO**](https://stackoverflow.com/a/15346857/10388096 "StackOverflow")

| | Ricorsione | Iterazione |
|-| ---------- | ---------- |
|**PRO**|eleganti e sintetici|molto più efficienti|
|**CONTRO**|inefficienti per maggior consumo di tempo e memoria, |complessi e ingombranti, difficili da mantenere|

Consumano + tempo (cicli di clock), e + memoria (min 4 byte x frame)

Un esempio: [(recursive-hello.c)](examples/recursive-hello.c "recursive-hello.c")
```c
void hello(int n){
	if (n == 0) return;
	
	printf("hello\n");
	hello(n - 1);
}
void main(){
	hello(4);
}
``` 


Nell'esempio la chiamata `hello(1000000)`
genererebbe un milione di stack frames, di size 4B, che **avrebbe bisogno** di uno stack di almeno **4000000B!!**.
Per confronto, il mio pc ne ha 1048576B reali che è già abbondante, ma  non essendo sufficiente il programma si ferma a stampare 'hello' 258048 volte e poi incotra **`Segmentation fault`** o **`Stack overflow`**


---

## Tail call

[link2]:https://dev.to/rohit/demystifying-tail-call-optimization-5bf3

Quando la chiamata ricorsiva è l'ultima istruzione in una funzione, la ricorsione viene detta 'tail recursion'.

>If a function is tail recursive, it's either making a simple recursive call or returning the value from that call. No computation is performed on the returned value. Thus, there is no real need to preserve the stack frame for that call. We won't need any of the local data once the tail recursive call is made: we don't have any more statements or computations left. We can simply modify the state of the frame as per the call arguments and jump back to the first statement of the function. No need to push a new stack frame! We can do this over and over again with just one stack frame! [source](link2)

Riutilizzando quindi lo stesso frame per più chiamate, tramite la 'Tail call optimization' è possibile ridurre il costo di spazio di ricorsione della funzione da O(n) a O(1).

Per esempio una funzione per il calcolo dell'n-esimo numero di [Fibonacci](examples/fibonacci.c "fibonacci.c"), con divide & conquer:
```c
int fibonacciDC(int n) {
	
	if(n == 0) return 0;
	if(n == 1) return 1;
	
	return (fibonacciDC(n-1) + fibonacciDC(n-2));
	//Attenzione! solo perchè è in fondo non vuol dire sia una tail call
}
```
sul mio pc con `fib(200000)` arriva in `Segmentation fault`, mentre la seguente [versione con tail recursion](examples/fibonacci.c "fibonacci.c")
```c
int fibonacciTail(int n, int a, int b){
	
	if (n == 0) return a;   
	if (n == 1) return b;
	
	return fibonacciTail(n - 1, b, a + b);	//tail call
}
```

è in grado di fornirmi il risultato.

![stack fibonacci D&C](https://rohitawate.github.io/images/posts/2019-07-10-tail-call-optimization/fib.png "stack per fibonacciDC")
![stack fibonacci w/tail](https://rohitawate.github.io/images/posts/2019-07-10-tail-call-optimization/fib_tail.png "stack per fibonacciTail")
[source](link2)

---

## Esercizi :confused: :disappointed: :broken_heart:

- funzione che calcola ricorsivamente la potenza di un numero dato base ed esponente. [soluzioni](examples/potenza.c "potenza.c")
- funzione ricorsiva che calcola il massimo comun denominatore di due interi. [soluzioni](examples/mcd.c "mcd.c")
- **PRO**: funzione che calcoli l'n-esimo numero di fibonacci (più soluzioni possibili). [soluzioni](examples/fibonacci.c "fibonacci.c")
- **PROx2**: solve the Knapsack problem, using recursion or dynamic programming.  Given a set of items, each with a weight and a value, determine the number of each item to include in a collection so that the total weight is less than or equal to a given limit and the total value is as large as possible.  [solutions](http://ranger.uta.edu/~kosmopo/cse2320/lectures/05-Recursion_DynamicProgramming.pdf)

---

with :heart: by [_Luigi Masini_](https://github.com/LuigiMasini)  | [buy me a coffee](https://youtu.be/dQw4w9WgXcQ)