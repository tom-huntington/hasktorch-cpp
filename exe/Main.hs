module Main where

--import HasktorchSkeleton
import Foreign
import Foreign.C.Types
import Torch
import qualified Torch.Internal.Type as ATen

foreign import ccall unsafe "answer_to_everything" answerToEverything
  :: CBool -> IO CInt

foreign import ccall unsafe "cpp_work" cppWork :: Ptr ATen.Tensor -> IO (Ptr ATen.Tensor)
foreign import ccall unsafe "cpp_input_tensor" cppInputTensor :: IO (Ptr ATen.Tensor)

--foldLoop :: a -> Int -> (a -> Int -> IO a) -> IO a
--foldLoop x count block = foldM block x [1 .. count]

main1 :: IO ()
main1 = do
  putStrLn "Hello Hasktorch!a"
  t <- withForeignPtr tt return
  ttt <- cppWork t
  x <- Unsafe <$> newForeignPtr_ ttt
  print x
  where
    Unsafe tt = asTensor ([0..5] :: [Float])

main :: IO ()
main = do
  foldLoop () 10 $ \() _ -> do
    y <- cppInputTensor
    x <- Unsafe <$> newForeignPtr_ y
    print x
    pure ()
  pure ()

