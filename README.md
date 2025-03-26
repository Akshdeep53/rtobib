# rtobib
Simple c++ program to convert .ris files in biblatex format. Multiple tags are available to the user. User can simply provide _input .ris files_ and name of the _output file_ (must have .bib extension) in which content of these input files will be converted into biblatex format. User can simply give path of the output file in there Latex file.

# Installation
Step 1: git clone the Repository<br/>
Step 2: 
```
make
```
Step 3: Add the executable file to path for easy access

# Usage
	-h, --help		  Show this help message
	-o, --output_file	  Specify the output file name
	-i, --input_file	  Specify the input file(s) name(s)
	-a, --all		  All the .ris files in current directory will be considered as input
Please avoid giving same _output file name_ if you don't want it to be appended with every execution.

 # Example
 Example 1:
 ```
rtobib -i input_1.ris input_2.ris -o output.bib
```
Example 2:
```
rtobib -a -o output.bib
```

