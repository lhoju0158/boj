SELECT C.APNT_NO, A.PT_NAME, A.PT_NO, C.MCDP_CD, B.DR_NAME, C.APNT_YMD
FROM APPOINTMENT AS C JOIN PATIENT AS A ON C.PT_NO = A.PT_NO JOIN DOCTOR AS B ON B.DR_ID = C.MDDR_ID
WHERE C.MCDP_CD = 'CS' AND C.APNT_CNCL_YN = 'N' AND C.APNT_YMD LIKE '2022-04-13%'
ORDER BY C.APNT_YMD