#include "SplitString.hpp"

void setup() {
  namespace sc = softcast;
  Serial.begin(115200);
  Serial.println("\n");

  auto splitted_c = sc::split_str("This is some C-style test string to split.");
  for (auto &&str : splitted_c){
    Serial.println(str);
  }
  
  Serial.println("\n--------\n");

  auto splitted_cpp = sc::split_str(String("This is some Arduino style test string to split."));

  for (auto &&str : splitted_cpp){
    Serial.println(str);
  }
}

void loop() {
}