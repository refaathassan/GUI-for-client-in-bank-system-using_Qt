@echo off

rem Check if private.pem exists and delete it
if exist private.pem (
    del private.pem
    echo Existing private.pem deleted.
)

rem Check if public.pem exists and delete it
if exist public.pem (
    del public.pem
    echo Existing public.pem deleted.
)

rem Generate private key in PEM format
openssl genrsa -out private.pem 2048

rem Generate public key from private key
openssl rsa -in private.pem -outform PEM -pubout -out public.pem

echo Keys generated successfully:
echo Private Key: private.pem
echo Public Key: public.pem

