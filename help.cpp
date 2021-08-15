#include <iostream>
#include <torch/torch.h>
#include <functional>

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

  void init_data_loader()
  {

  }

  auto data_loader = torch::data::make_data_loader(
      torch::data::datasets::MNIST("./data").map(
          torch::data::transforms::Stack<>()),
      /*batch_size=*/1);

  torch::Tensor* cpp_input_tensor()
  {
    
    
    auto& a = *data_loader;
    auto b = a.begin();
    auto c = *b;
    auto d = c.data;
    auto e = c.target;
    auto* f = d.data_ptr();
    
    
    
    std::cout << "Hi from C++\n";
    //auto* ten = (torch::Tensor*)malloc(sizeof(torch::Tensor));
    auto* ten = new torch::Tensor;
    std::cout << ten << std::endl << *ten << std::endl << "By C++\n";
    *ten = std::move(d);//torch::rand({2, 3});

    return ten;
  }
}
