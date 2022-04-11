# This Repo is a hodgpodge of commands I find useful.

## Docker Quickies

### list docker images

docker image ls

### list docker containers

docker ps <br>
docker ps -a

### copy files from container to local drive
1. step into the host directory
2. run docker cp containerID: [path to file] [newfilename]
 
example: <br>
docker cp e6717a8856c6:/usr/src/vera/ShortStack/ShortStack/output/bc_counts.tsv bc_counts2.tsv
/usr/src/vera/ShortStack/ShortStack/output

### copy files from local drive to container 
docker cp C:/Users/vdiaz/Downloads/blais-snakefood-747c6890354a 61558cdd9828:/usr/src/vera/

### save changes to container

docker commit [container id] [image name]

---
## shell-commands w/ purpose

### For Matlab
Extract comments using:

grep -e '%%%*' *.m > deleteMe_comments2.txt

Extract Functions:

grep -e 'function*' *.m

---
### For Clojure Project
 below are the steps to extract just the namespace from the repl output.
 example of repl output: 
 object[clojure.lang.Namespace 0x81ba853 "clojure.tools.logging"])
 from that output I only want the string within the quotes

#### Notes on Grep and Sed for modifying clojure doc

grep will find lines with "(defn " and the line that follows it
sed will remove defn and the quotes
<font face="Arial">
 grep -A 1 -e '(defn' core.clj | sed "s/(defn//g"|sed 's/"//g'
</font>

#### List of namespaces was captured as follows: 
1.	Launch the prototype in the IDE
2.	Launch the REPL
3.	In the REPL run: (all-ns)
4.	Save the output to a file called all-ns.txt
5.	Open git bash in the directory with the all-ns.txt file and run: 

<font face="Arial"> 
grep -E '*dx-prototype*' all-ns.txt | grep -o '".*"'|sed 's/"//g' | sed 's/dx-prototype.//'> prototype-ns.txt
 
grep -o '".*"' namespaces.txt | sed 's/"//g' > namespacelist_vera.txt

</font>

Get the line that follows the function for all functions in a file. Process by stepping into each directory using git bash for windows:
<font face="Arial"> 
grep -A 1 -e '(defn' [filename] | sed "s/(defn//g"|sed 's/"//g'
</font>

---

## Documentation on shell commands:
Ref1: (grep --help) 
Ref2: http://www.ericagamet.com/wp-content/uploads/2016/04/Erica-Gamets-GREP-Cheat-Sheet.pdf
 
## Commands you can apply to files within a directory

append all text files in a directory into one file
cat *txt > all.txt

# Change the file Names of Files in Directory

rename 's/ +\././; y/_/-/; s/(.*?-)/\L$1/' '1_Table_of_Contents.pdf'
rename 's/ +\././; y/ /-/; s/(.*?-)/\L$1/' *
