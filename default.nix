{ stdenv, gcc, gtest, lib }:

stdenv.mkDerivation rec {
  pname = "unit-test-learning";
  version = "0.1";

  src = ./.; 

  buildInputs = [ stdenv gcc gtest ];

  doCheck = true;
  buildPhase = ''
    g++ -o tests test/main_test.cpp -lgtest -lpthread
  '';

  checkPhase = ''
    ./tests
  '';

  meta = with lib; {
    description = "A simple C++ project with Google Test and Nix";
    platforms = platforms.linux;
  };
}
