/********************************************************************************
* lin_reg.cpp: Definition av funktionsmedlemmar tillhörande strukten lin_reg,
*              som används för implementering av enkla maskininlärningsmodeller
*              som baseras på linjär regression.
********************************************************************************/
#include "lin_reg.hpp"

/********************************************************************************
* set_training_data: Läser in träningsdata för angiven regressionsmodell via
*                    passerad in- och utdata, tillsammans med att index
*                    för respektive träningsuppsättning lagras.
*
*                    - x   : Innehåller indata för träningsuppsättningar.
*                    - yref: Innehåller utdata för träningsuppsättningar.
********************************************************************************/
void lin_reg::set_training_data(const std::vector<double>& x,
                                const std::vector<double>& yref)
{
}

/********************************************************************************
* train: Tränar angiven regressionsmodell under angivet antal epoker med
*        angiven lärhastighet. För varje epok randomiseras ordningsföljden
*        som träningsdatan används för att undvika att modellen inte blir
*        för bekant med träningsdatan (vi undviker overfitting).
* 
*        - num_epochs   : Antalet omgångar träning som skall genomföras.
*        - learning_rate: Lärhastighet, avgör justeringsgraden.
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
* predict: Genomför prediktion med angiven regressionsmodell via indata från
*          samtliga befintliga träningsuppsättningar och skriver ut varje
*          insignal samt motsvarande predikterat värde via angiven utström
*          där standardutenheten std::cout används som default för utskrift
*          i terminalen.
*
*          - ostream: Angiven utström (default = std::cout).
********************************************************************************/
void lin_reg::predict(std::ostream& ostream)
{
}

/********************************************************************************
* predict_range: Genomför prediktion med angiven regressionsmodell för
*                datapunkter inom intervallet mellan angivet min- och maxvärde
*                [min, max] med angiven stegringshastighet step, som sätts till
*                1.0 som default.
*
*                Varje insignal skrivs ut tillsammans med motsvarande
*                predikterat värde via angiven utström, där standardutenheten
*                std::cout används som default för utskrift i terminalen.
*
*                - min    : Lägsta värde för datatpunkter som skall testas.
*                - max    : Högsta värde för datatpunkter som skall testas.
*                - step   : Stegringshastigheten, dvs. differensen mellan
*                           varje datapunkt som skall testas (default = 1.0).
                 - ostream: Angiven utström (default = std::cout).
********************************************************************************/
void lin_reg::predict_range(const double min, 
                            const double max, 
                            const double step, 
                            std::ostream& ostream)
{
}

/********************************************************************************
* shuffle: Randomiserar den inbördes ordningen på träningsuppsättningarna för
*          angiven regressionsmodell, vilket genomförs i syfte att minska risken
*          för att eventuella icke avsedda mönster i träningsdatan skall
*          påverka träningen.
********************************************************************************/
void lin_reg::shuffle(void)
{
}

/********************************************************************************
* optimize: Beräknar aktuell avvikelse för angiven regressionsmodell och 
*           justerar modellens parametrar därefter.
*
*           input        : Insignal som prediktion skall genomföras med.
*           reference    : Referensvärde från träningsdatan, vilket utgör det
*                          värde som modellen önskas prediktera.
*           learning_rate: Modellens lärhastighet, avgör hur mycket modellens
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