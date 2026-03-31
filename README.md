# 2026-I-CS-UNI-CC112-B-FundProg

Sincronizar nuevas ramas que van apareciendo en e repo del profesor:

git remote -v
git remote add upstream https://github.com/ecuadros/2026-I-CS-UNI-CC112-B-FundProg.git
git fetch upstream
git branch -r

git checkout -b 01-main upstream/01-main
git push -u origin 01-main

git checkout -b 02-gitignore upstream/02-gitignore
git push -u origin 02-gitignore
