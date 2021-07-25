#include <iostream>
#include <torch/torch.h>

extern "C" {
  int answer_to_everything(bool arg);

  int answer_to_everything(bool arg) {
    std::cout << "Hello from C++\n";
    return 4532;
  }

  torch::Tensor* cpp_work(torch::Tensor* p)
  {
    std::cout << *p << std::endl;
    std::cout << "Bye from C++\n";
    auto* ten = new torch::Tensor;
    *ten = torch::rand({2, 3});
    return ten;

  }
  
  torch::Tensor* cpp_input_tensor()
  {
    std::cout << "Hi from C++\n";
    auto* ten = new torch::Tensor;
    *ten = torch::rand({2, 3});
    return ten;
  }
}
