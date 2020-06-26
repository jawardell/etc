# !/bin/bash

for f in *.log; do
  mv -- "$f" "${f%.log}.txt"
done
