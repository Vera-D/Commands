@echo ON

:: Get the number of lines in the file
set LINES=0
for /f "delims==" %%I in (full_20m.tsv) do (
    set /a LINES=LINES+1
	echo LINES
)

:: Print the last 10 lines (suggestion to use more courtsey of dmityugov)
set /a LINES=LINES-10
more +%LINES% < full_20m.tsv