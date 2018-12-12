# Touch

## Install
> git clone https://github.com/siskinc/touch  
  cd touch  
  rm -rf touch  
  git clone https://github.com/siskinc/cmdline  
  cd ..  
  make test  
  make  
  make install_template  
  make install  

## Example

### A template file
> filename: ~/.touch/cpp
``` cpp
/*
** Author: {USER}
** Create: {TIME}
*/
#include <iostream>

int main(int argc, char **argv)
{{

    return 0;
}}
```

### Result
> cmd:  
  touch a.cpp

```cpp
/*
** Author: daryl
** Create: 2018-12-12
*/
#include <iostream>

int main(int argc, char **argv)
{

    return 0;
}
```
