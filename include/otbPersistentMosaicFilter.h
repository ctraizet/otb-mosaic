#ifndef MODULES_REMOTE_MOSAIC_INCLUDE_OTBPERSISTENTMOSAICFILTER_H_
#define MODULES_REMOTE_MOSAIC_INCLUDE_OTBPERSISTENTMOSAICFILTER_H_

#include "otbStreamingMosaicFilterBase.h"

namespace otb
{
/** \class PersistentMosaicFilter
 *  \brief This filter is the base class for all mosaic filter persisting data through multiple
 *   update.
 *   For instance, a filter computing global statistics on an mosaic with streaming
 *   capabilities will have to keep the temporary results for each streamed piece of the
 *   image in order to synthesize the global statistics at the end. This filter is an
 *   itk::ImageToImageFilter, providing two additional methods. The first one, Synthetize(),
 *   allows the user to synthesize temporary data produced by the multiple updates on different
 *   pieces of the image to the global result. The second one, Reset(), allows the user to
 *   reset the temporary data for a new input image for instance.
 *
 *  \note This class contains pure virtual method, and can not be instantiated.
 *
 * \sa PersistentMosaicFilter
 * \sa StreamingStatisticsMosaicFilter
  *
 * \ingroup OTBMosaic
 */
template <class TInputImage, class TOutputImage, class TPrecisionType>
class ITK_EXPORT PersistentMosaicFilter : public otb::StreamingMosaicFilterBase<TInputImage, TOutputImage, TPrecisionType>
{
public:
  /** Standard typedefs */
  typedef PersistentMosaicFilter                              Self;
  typedef otb::StreamingMosaicFilterBase<TInputImage, TOutputImage, TPrecisionType> Superclass;
  typedef itk::SmartPointer<Self>                            Pointer;
  typedef itk::SmartPointer<const Self>                      ConstPointer;

  /** Creation through object factory macro */
  itkTypeMacro(PersistentMosaicFilter, StreamingMosaicFilterBase);

  /** Input image typedefs.  */
  typedef typename Superclass::InputImageType              InputImageType;
  typedef typename Superclass::InputImagePointer           InputImagePointer;
  typedef typename Superclass::InputImagePointType         InputImagePointType;
  typedef typename Superclass::InputImagePixelType         InputImagePixelType;
  typedef typename Superclass::InputImageIndexType         InputImageIndexType;
  typedef typename Superclass::InputImageSizeType          InputImageSizeType;
  typedef typename Superclass::InputImageSpacingType       InputImageSpacingType;
  typedef typename Superclass::InputImageInternalPixelType InputImageInternalPixelType;
  typedef typename Superclass::InputImageRegionType        InputImageRegionType;

  /** Output image typedefs.  */
  typedef typename Superclass::OutputImageType              OutputImageType;
  typedef typename Superclass::OutputImagePointer           OutputImagePointer;
  typedef typename Superclass::OutputImagePointType         OutputImagePointType;
  typedef typename Superclass::OutputImagePixelType         OutputImagePixelType;
  typedef typename Superclass::OutputImageIndexType         OutputImageIndexType;
  typedef typename Superclass::OutputImageSizeType          OutputImageSizeType;
  typedef typename Superclass::OutputImageSpacingType       OutputImageSpacingType;
  typedef typename Superclass::OutputImageInternalPixelType OutputImageInternalPixelType;
  typedef typename Superclass::OutputImageRegionType        OutputImageRegionType;

  /** Internal computing typedef support. */
  typedef typename Superclass::InternalValueType       InternalValueType;
  typedef typename Superclass::ContinuousIndexType     ContinuousIndexType;
  typedef typename Superclass::InterpolatorType        InterpolatorType;
  typedef typename Superclass::InterpolatorPointerType InterpolatorPointerType;
  typedef typename Superclass::DefaultInterpolatorType DefaultInterpolatorType;
  typedef typename Superclass::InternalImageType       InternalImageType;
  typedef typename Superclass::InternalPixelType       InternalPixelType;
  typedef typename Superclass::IteratorType            IteratorType;
  typedef typename Superclass::ConstIteratorType       ConstIteratorType;
  typedef typename Superclass::StreamingTraitsType     StreamingTraitsType;

  /**
   * Reset the persistent data of the filter.
   */
  virtual void Reset(void) = 0;
  /**
   * Synthesize the persistent data of the filter.
   */
  virtual void Synthetize(void) = 0;

protected:
  /** Constructor */
  PersistentMosaicFilter() {}
  /** Destructor */
  ~PersistentMosaicFilter() ITK_OVERRIDE {}
  /**PrintSelf method */
  void PrintSelf(std::ostream& os, itk::Indent indent) const ITK_OVERRIDE
  {
    Superclass::PrintSelf(os, indent);
  }

private:
  PersistentMosaicFilter(const Self &); //purposely not implemented
  void operator =(const Self&); //purposely not implemented
};
} // End namespace otb



#endif /* MODULES_REMOTE_MOSAIC_INCLUDE_OTBPERSISTENTMOSAICFILTER_H_ */
