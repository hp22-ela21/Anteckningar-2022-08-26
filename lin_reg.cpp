/********************************************************************************
* lin_reg.cpp: Definition av funktionsmedlemmar tillh�rande strukten lin_reg,
*              som anv�nds f�r implementering av enkla maskininl�rningsmodeller
*              som baseras p� linj�r regression.
********************************************************************************/
#include "lin_reg.hpp"

/********************************************************************************
* set_training_data: L�ser in tr�ningsdata f�r angiven regressionsmodell via
*                    passerad in- och utdata, tillsammans med att index
*                    f�r respektive tr�ningsupps�ttning lagras.
*
*                    - x   : Inneh�ller indata f�r tr�ningsupps�ttningar.
*                    - yref: Inneh�ller utdata f�r tr�ningsupps�ttningar.
********************************************************************************/
void lin_reg::set_training_data(const std::vector<double>& x,
                                const std::vector<double>& yref)
{
}

/********************************************************************************
* train: Tr�nar angiven regressionsmodell under angivet antal epoker med
*        angiven l�rhastighet. F�r varje epok randomiseras ordningsf�ljden
*        som tr�ningsdatan anv�nds f�r att undvika att modellen inte blir
*        f�r bekant med tr�ningsdatan (vi undviker overfitting).
* 
*        - num_epochs   : Antalet omg�ngar tr�ning som skall genomf�ras.
*        - learning_rate: L�rhastighet, avg�r justeringsgraden.
********************************************************************************/
void lin_reg::train(const std::size_t num_epochs,
                    const double learning_rate)
{
   for (std::size_t i = 0; i < num_epochs; ++i)
   {
      this->shuffle();

      for (std::size_t j = 0; j < this->num_sets(); ++j)
      {
         const auto k = this->train_order[j];
         this->optimize(this->x[k], this->yref[k], learning_rate);
      }
   }

   return;
}

/********************************************************************************
* predict: Genomf�r prediktion med angiven regressionsmodell via indata fr�n
*          samtliga befintliga tr�ningsupps�ttningar och skriver ut varje
*          insignal samt motsvarande predikterat v�rde via angiven utstr�m
*          d�r standardutenheten std::cout anv�nds som default f�r utskrift
*          i terminalen.
*
*          - ostream: Angiven utstr�m (default = std::cout).
********************************************************************************/
void lin_reg::predict(std::ostream& ostream)
{
}

/********************************************************************************
* predict_range: Genomf�r prediktion med angiven regressionsmodell f�r
*                datapunkter inom intervallet mellan angivet min- och maxv�rde
*                [min, max] med angiven stegringshastighet step, som s�tts till
*                1.0 som default.
*
*                Varje insignal skrivs ut tillsammans med motsvarande
*                predikterat v�rde via angiven utstr�m, d�r standardutenheten
*                std::cout anv�nds som default f�r utskrift i terminalen.
*
*                - min    : L�gsta v�rde f�r datatpunkter som skall testas.
*                - max    : H�gsta v�rde f�r datatpunkter som skall testas.
*                - step   : Stegringshastigheten, dvs. differensen mellan
*                           varje datapunkt som skall testas (default = 1.0).
                 - ostream: Angiven utstr�m (default = std::cout).
********************************************************************************/
void lin_reg::predict_range(const double min, 
                            const double max, 
                            const double step, 
                            std::ostream& ostream)
{
}

/********************************************************************************
* shuffle: Randomiserar den inb�rdes ordningen p� tr�ningsupps�ttningarna f�r
*          angiven regressionsmodell, vilket genomf�rs i syfte att minska risken
*          f�r att eventuella icke avsedda m�nster i tr�ningsdatan skall
*          p�verka tr�ningen.
********************************************************************************/
void lin_reg::shuffle(void)
{
}

/********************************************************************************
* optimize: Ber�knar aktuell avvikelse f�r angiven regressionsmodell och 
*           justerar modellens parametrar d�refter.
*
*           input        : Insignal som prediktion skall genomf�ras med.
*           reference    : Referensv�rde fr�n tr�ningsdatan, vilket utg�r det
*                          v�rde som modellen �nskas prediktera.
*           learning_rate: Modellens l�rhastighet, avg�r hur mycket modellens
*                          parametrar justeras vid avvikelse.
********************************************************************************/
void lin_reg::optimize(const double input,
                       const double reference,
                       const double learning_rate)
{
   const auto prediction = this->predict(input);       
   const auto deviation = reference - prediction;     
   const auto change_rate = deviation * learning_rate; 

   this->bias += change_rate;                          
   this->weight += change_rate * input;             
   return;
}