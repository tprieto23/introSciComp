#include <random>
#include <iostream>
#include <cstdlib>
#include <vector>

void compute_pdf(int seed, int nsamples, double mu, double sigma, double xmin, double xmax, int nbins);

int main(int argc, char **argv)
{
  const int SEED = std::atoi(argv[1]);
  const int NSAMPLES = std::atoi(argv[2]);
  const double MU = std::atof(argv[3]);
  const double SIGMA = std::atof(argv[4]);
  const double XMIN = std::atof(argv[5]);
  const double XMAX = std::atof(argv[6]);
  const int NBINS = std::atoi(argv[7]);

  compute_pdf(SEED, NSAMPLES, MU, SIGMA, XMIN, XMAX, NBINS);
}

void compute_pdf(int seed, int nsamples, double mu, double sigma, double xmin, double xmax, int nbins)
{
  // random stuff
  std::mt19937 gen(seed);
  std::normal_distribution<double> dis{mu, sigma};

  // histogram stuff
  std::vector<int> histogram(nbins, 0);

  for(int n = 0; n < nsamples; ++n) {
    double r = dis(gen);
    int bin = static_cast<int>((r - xmin) / (xmax - xmin) * nbins);
    // Check for outliers
    if (bin >= 0 && bin < nbins) {
      ++histogram[bin];
    }
  }
  
  // compute and print the pdf
  double sum = 0.0;
  for (int i = 0; i < nbins; ++i) {
    sum += static_cast<double>(histogram[i]);
  }

  for (int i = 0; i < nbins; ++i) {
    double binCenter = xmin + (i + 0.5) * (xmax - xmin) / nbins;
    double binWidth = (xmax - xmin) / nbins;
    double pdfValue = static_cast<double>(histogram[i]) / sum;

    std::cout << binCenter << " " << pdfValue << "\n";
  }

}
