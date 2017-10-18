# shell-commands
## For Clojure Project
 below are the steps to extract just the namespace from the repl output.
 example of repl output: 
 object[clojure.lang.Namespace 0x81ba853 "clojure.tools.logging"])
 from that output I only want the string within the quotes

 step1 use the repl to extract all namespaces
(all-ns)

 step2 save the output to a text file
 todo: find out how to do this from within the repl. Right now I just copy paste

 step3 use shell commands to extract the namespace within the quotes
 grep will extract the string within quotes
 sed will remove the quotes

grep -o '".*"' namespaces.txt | sed 's/"//g' > namespacelist_vera.txt

 Documentation on shell commands:
 Ref1: (grep --help) 
 Ref2: http://www.ericagamet.com/wp-content/uploads/2016/04/Erica-Gamets-GREP-Cheat-Sheet.pdf
 
