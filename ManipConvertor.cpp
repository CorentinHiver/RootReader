//g++ ManipConvertor.cpp  $(root-config --glibs --cflags --libs) $(pkg-config  --cflags --libs libfasterac) -o ManipConvertor -O2 -Wall -pthread -std=c++17

#define N_SI_129
#define PARIS
#define QDC2
#define USE_DSSD
#define FATIMA

#include "lib/utils.hpp"
Labels g_labelToName;
#include "lib/Event.hpp"
#include "lib/FilesManager.hpp"

#include "Classes/Parameters.hpp"
#include "Modules/EachDetector.hpp"


int main(int argc, char ** argv)
{

  Parameters p;
  if (!p.setParameters(argc, argv)) return (-1);
  p.readParameters();

  TChain chain("Nuball");
  std::string rootfile;
  while(p.files().nextFileName(rootfile)) chain.Add(rootfile.c_str());

  Event event(&chain);

  std::unique_ptr<TFile> file(TFile::Open("run.root","recreate"));
  auto outTree = new TTree("Nuball2", "New conversion");
  outTree -> Branch("mult", &event.mult);

  int nb = chain.GetEntries();
  for (int i = 0; i<nb; i++)
  {
    chain.GetEntry(i);
    ed.Fill(event);
    if ()
  }

  return 1;
}
