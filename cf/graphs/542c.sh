for (( i = 1; i <= 100; ++i )); do
  ./542c_gen > in
  ./542c < in > out1
  ./542c_brute < in > out2
  diff -w out1 out2 
  if [[ $? == 0 ]]; then
    echo 'TC' $i '- \033[32mPASSED\033[0m'
  else 
    echo 'TC' $i '- \033[31mFAILED\033[0m'
  fi
done
